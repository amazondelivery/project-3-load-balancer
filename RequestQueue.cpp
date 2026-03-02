#include "RequestQueue.h"
#include <queue>

RequestQueue::RequestQueue(int size) {
    for (int i = 0; i < size; i++) {
        queue.push(Request());
    }
}

void RequestQueue::push(Request req) {
    queue.push(req);
}

bool RequestQueue::empty() const {
    return queue.empty();
}

Request RequestQueue::pop() {
    Request frontRequest = queue.front();
    queue.pop();
    return frontRequest;
}

Request RequestQueue::peek() {
    Request req = queue.front();
    return req;
}

int RequestQueue::size() const {
    return queue.size();
}