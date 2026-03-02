#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

class RequestQueue {
public:
    RequestQueue(int size);
    void push(Request req);
    bool empty() const;
    Request pop();
    int size() const;

private:
    std::queue<Request> queue;
};

#endif