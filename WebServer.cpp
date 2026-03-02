#include "WebServer.h"
#include <iostream>

WebServer::WebServer(int id) {
    remainingTime = 0;
    serverID = id;
}

void WebServer::process(Request req) {
    remainingTime = req.time;

    std::cout << "WebServer " << serverID << " just took on new request. Webserver" << serverID << " will be processing request for " << remainingTime << " more ticks..." << std::endl;
}

void WebServer::tick() {
    if (remainingTime > 0) {
        remainingTime--;
        if (remainingTime != 0) {
            std::cout << "WebServer " << serverID << " is processing, remaining time: " << remainingTime << "..." << std::endl;
        }
    } else {
        std::cout << "WebServer " << serverID << " is available..." << std::endl;
    }
}

bool WebServer::isProcessing() {
    return remainingTime > 0;
}