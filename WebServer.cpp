#include "WebServer.h"

WebServer::WebServer() {
    remainingTime = 0;
}

void WebServer::process(Request req) {
    remainingTime = req.time;
}

void WebServer::tick() {
    if (remainingTime > 0) {
        remainingTime--;
    }
}

bool WebServer::isProcessing() {
    return remainingTime > 0;
}