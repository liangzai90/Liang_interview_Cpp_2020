// Server.h

#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <vector>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <atomic>

class Server {
public:
    Server();
    ~Server();
    void start(int port);
    void waitForShutdown();
    void sendHeartbeat();
    void mainLoop();

private:
    int createSocket(int port);
    void acceptClients();
    void handleClient(int clientSock);
    void receiveMessage(int clientSock);
    void sendMessage(int clientSock, const std::string& message);
    void closeClient(int clientSock);

private:
    int serverSock;
    int epollFd;
    std::vector<int> clientSocks;
    std::atomic<bool> shutdownRequested;
};

#endif // SERVER_H
