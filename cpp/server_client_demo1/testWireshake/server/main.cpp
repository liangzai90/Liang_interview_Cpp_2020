// main.cpp

#include <iostream>
#include <memory>
#include <thread>
#include "server.h"
#include "logger.h"

int main() {
    try {
        // Initialize logger

        Logger::getInstance().init("socketDemo");
        

        // Start server
        std::shared_ptr<Server> server = std::make_shared<Server>();
        server->start(5566);

        // Start heartbeat thread
        std::thread heartbeatThread([&server]() {
            while (true) {
                std::this_thread::sleep_for(std::chrono::seconds(10));
                server->sendHeartbeat();
            }
        });

        // Wait for server to finish
        server->waitForShutdown();

        // Join heartbeat thread
        heartbeatThread.join();

    } catch (std::exception& e) {
        LOG_ERROR("Exception: " << e.what());
    }

    return 0;
}
