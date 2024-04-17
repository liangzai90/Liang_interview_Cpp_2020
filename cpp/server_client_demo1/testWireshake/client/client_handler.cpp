#include "client_handler.h"

ClientHandler::ClientHandler(const char* server_ip, int server_port, int pid)
    : server_ip(server_ip), server_port(server_port), pid(pid), counter(0) {}

void ClientHandler::start() {
    connectToServer();

    // Send initial message
    std::string initial_message = "i am " + std::to_string(pid);
    sendMessage(initial_message);

    // Start sending hello world messages every 3 seconds
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::string hello_message = "hello world " + std::to_string(counter++);
        sendMessage(hello_message);
        receiveMessage();
    }
}

void ClientHandler::connectToServer() {
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Error: Failed to create socket." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set up server address
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == -1) {
        std::cerr << "Error: Failed to connect to server." << std::endl;
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    std::cout << "Connected to server." << std::endl;
}

void ClientHandler::sendMessage(const std::string& message) {
    if (send(sockfd, message.c_str(), message.size(), 0) == -1) {
        std::cerr << "Error: Failed to send message." << std::endl;
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    std::cout << "Sent message: " << message << std::endl;
}

void ClientHandler::receiveMessage() {
    char buffer[1024] = {0};
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        std::cerr << "Error: Failed to receive message." << std::endl;
        close(sockfd);
        exit(EXIT_FAILURE);
    } else if (bytes_received == 0) {
        std::cout << "Server closed the connection." << std::endl;
        close(sockfd);
        exit(EXIT_SUCCESS);
    } else {
        std::cout << "Received message from server: " << buffer << std::endl;
    }
}
