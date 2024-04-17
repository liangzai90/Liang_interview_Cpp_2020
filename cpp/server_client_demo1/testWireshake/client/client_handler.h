#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class ClientHandler {
public:
    ClientHandler(const char* server_ip, int server_port, int pid);
    void start();

private:
    const char* server_ip;
    int server_port;
    int pid;
    int counter; // Counter for hello world messages
    int sockfd;

    void connectToServer();
    void sendMessage(const std::string& message);
    void receiveMessage();
};

#endif // CLIENT_HANDLER_H
