// Server.cpp

#include "server.h"
#include "logger.h"
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <arpa/inet.h>  
const int MAX_EVENTS = 1024;
// #include <iostream>
// #include <log4cplus/helpers/loglog.h>
// #include <log4cplus/logger.h>
// #include <log4cplus/initializer.h>

// using namespace std;
// using namespace log4cplus::helpers;


Server::Server() : serverSock(-1), epollFd(-1), shutdownRequested(false) {}

Server::~Server() {
    if (serverSock != -1)
        close(serverSock);
    if (epollFd != -1)
        close(epollFd);
}
void Server::start(int port) {
    // Create server socket
    serverSock = createSocket(port);

    // Create epoll instance
    epollFd = epoll_create1(0);
    if (epollFd == -1) {
        LOG_ERROR("Failed to create epoll instance: " << strerror(errno));
        throw std::runtime_error("Failed to create epoll instance");
    }

    // Add server socket to epoll
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = serverSock;
    if (epoll_ctl(epollFd, EPOLL_CTL_ADD, serverSock, &event) == -1) {
        LOG_ERROR("Failed to add server socket to epoll: " << strerror(errno));
        throw std::runtime_error("Failed to add server socket to epoll");
    }

    // Start a new thread to handle main loop
    std::thread mainLoopThread([this]() {
        mainLoop();
    });
    mainLoopThread.detach();

    LOG_INFO("Server started on port " << port);
}

void Server::mainLoop() {
    struct epoll_event events[MAX_EVENTS];
    while (!shutdownRequested) {
        int numEvents = epoll_wait(epollFd, events, MAX_EVENTS, -1);
        if (numEvents == -1) {
            if (errno != EINTR) {
                LOG_ERROR("Error in epoll_wait: " << strerror(errno));
            }
            continue;
        }

        for (int i = 0; i < numEvents; ++i) {
            if (events[i].data.fd == serverSock) {
                acceptClients();
            } else if (events[i].events & EPOLLIN) {
                handleClient(events[i].data.fd);
            }
        }
    }

    LOG_INFO("Server shutting down");
}



void Server::waitForShutdown() {
    while (!shutdownRequested) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Server::sendHeartbeat() {
    std::string heartbeatMessage = "heart beat, I am live.";
    for (int clientSock : clientSocks) {
        sendMessage(clientSock, heartbeatMessage);
    }
}

int Server::createSocket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        LOG_ERROR("Failed to create server socket: " << strerror(errno));
        throw std::runtime_error("Failed to create server socket");
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        LOG_ERROR("Failed to set socket options: " << strerror(errno));
        throw std::runtime_error("Failed to set socket options");
    }

    // Bind socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) == -1) {
        LOG_ERROR("Failed to bind server socket: " << strerror(errno));
        throw std::runtime_error("Failed to bind server socket");
    }

    // Listen for connections
    if (listen(sock, SOMAXCONN) == -1) {
        LOG_ERROR("Failed to listen on server socket: " << strerror(errno));
        throw std::runtime_error("Failed to listen on server socket");
    }

    return sock;
}

void Server::acceptClients() {
    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientSock = accept(serverSock, reinterpret_cast<struct sockaddr*>(&clientAddr), &clientLen);
    if (clientSock == -1) {
        LOG_ERROR("Failed to accept client connection: " << strerror(errno));
        return;
    }

    LOG_INFO("Accepted client connection from " << inet_ntoa(clientAddr.sin_addr));

    // Set client socket to non-blocking
    int flags = fcntl(clientSock, F_GETFL, 0);
    if (flags == -1) {
        LOG_ERROR("Failed to get client socket flags: " << strerror(errno));
        close(clientSock);
        return;
    }
    if (fcntl(clientSock, F_SETFL, flags | O_NONBLOCK) == -1) {
        LOG_ERROR("Failed to set client socket to non-blocking: " << strerror(errno));
        close(clientSock);
        return;
    }

    // Add client socket to epoll
    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = clientSock;
    if (epoll_ctl(epollFd, EPOLL_CTL_ADD, clientSock, &event) == -1) {
        LOG_ERROR("Failed to add client socket to epoll: " << strerror(errno));
        close(clientSock);
        return;
    }

    clientSocks.push_back(clientSock);
}

void Server::handleClient(int clientSock) {
    receiveMessage(clientSock);
}

void Server::receiveMessage(int clientSock) {
    char buffer[1024];
    ssize_t bytesRead = recv(clientSock, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        if (errno != EWOULDBLOCK && errno != EAGAIN) {
            LOG_ERROR("Failed to receive message from client: " << strerror(errno));
            closeClient(clientSock);
        }
    } else if (bytesRead == 0) {
        LOG_INFO("Client disconnected");
        closeClient(clientSock);
    } else {
        std::string message(buffer, bytesRead);
        LOG_INFO("Received message from client: " << message);
        // Handle received message here
    }
}

void Server::sendMessage(int clientSock, const std::string& message) {
    ssize_t bytesSent = send(clientSock, message.c_str(), message.size(), 0);
    if (bytesSent == -1) {
        LOG_ERROR("Failed to send message to client: " << strerror(errno));
        closeClient(clientSock);
    }
}

void Server::closeClient(int clientSock) {
    epoll_ctl(epollFd, EPOLL_CTL_DEL, clientSock, nullptr);
    close(clientSock);
    clientSocks.erase(std::remove(clientSocks.begin(), clientSocks.end(), clientSock), clientSocks.end());
}
