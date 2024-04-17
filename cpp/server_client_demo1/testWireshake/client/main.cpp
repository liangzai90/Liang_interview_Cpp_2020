#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "client_handler.h"

int main() {
    const char* server_ip = "192.168.10.108";
    const int server_port = 5566;
    int pid = getpid(); // Get process ID

    ClientHandler client_handler(server_ip, server_port, pid);

    // Start client handler thread
    std::thread handler_thread(&ClientHandler::start, &client_handler);

    // Keep main thread running
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
