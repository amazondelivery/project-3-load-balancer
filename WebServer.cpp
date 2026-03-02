#include "WebServer.h"
#include <iostream>

WebServer::WebServer(int id) {
    remainingTime = 0;
    serverID = id;
}

void WebServer::process(Request req) {
    remainingTime = req.time;

    std::cout << "Web Server " << serverID << " just took on new request. Web server " << serverID << " will be processing request for " << remainingTime << " more ticks..." << std::endl;
}

void WebServer::tick() {
    if (remainingTime > 0) {
        remainingTime--;
        if (remainingTime != 0) {
            std::cout << "Web Server " << serverID << " is processing, remaining time: " << remainingTime << "..." << std::endl;
        }
    } else {
        std::cout << "Web Server " << serverID << " is available..." << std::endl;
    }
}

bool WebServer::isProcessing() {
    return remainingTime > 0;
}