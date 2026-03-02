#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class WebServer {
private:
    int remainingTime;

public:
    WebServer();
    void process(Request req);
    void tick();
    bool isProcessing();
};

#endif