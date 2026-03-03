#include "WebServer.h"
#include <iostream>

/**
 * @brief Constructs a WebServer with a given ID (no job type).
 *
 * Used by LoadBalancer, which handles all job types.
 *
 * @param id int The unique identifier for this WebServer.
 */
WebServer::WebServer(int id) {
    remainingTime = 0;
    serverID = id;
}

/**
 * @brief Constructs a WebServer with a given ID and job type.
 *
 * Used by Switch, which restricts servers to a specific job type.
 *
 * @param id int The unique identifier for this WebServer.
 * @param type char The job type this server handles: 'P' (processing) or 'S' (streaming).
 */
WebServer::WebServer(int id, char type) {
    remainingTime = 0;
    serverID = id;
    this->type = type;
}

/**
 * @brief Assigns a new Request to this WebServer for processing.
 *
 * Sets the remaining processing time based on the Request's duration.
 *
 * @param req Request The Request object to process.
 */
void WebServer::process(Request req) {
    remainingTime = req.time;
    std::cout << "Web Server " << serverID
              << " just took on new request. Web server " << serverID
              << " will be processing request for " << remainingTime
              << " more ticks..." << std::endl;
}

/**
 * @brief Advances this WebServer by one clock cycle.
 *
 * Decrements remainingTime if busy, or logs availability if idle.
 */
void WebServer::tick() {
    if (remainingTime > 0) {
        remainingTime--;
        if (remainingTime != 0) {
            std::cout << "Web Server " << serverID
                      << " is processing, remaining time: " << remainingTime
                      << "..." << std::endl;
        }
    } else {
        std::cout << "Web Server " << serverID << " is available..." << std::endl;
    }
}

/**
 * @brief Checks whether this WebServer is currently processing a Request.
 *
 * @return bool true if the server is busy, false if it is available.
 */
bool WebServer::isProcessing() {
    return remainingTime > 0;
}