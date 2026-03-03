#include "RequestQueue.h"
#include <queue>

/**
 * @brief Constructs a RequestQueue and pre-fills it with randomized Requests.
 *
 * @param size int The number of Request objects to generate and enqueue on startup.
 */
RequestQueue::RequestQueue(int size) {
    for (int i = 0; i < size; i++) {
        queue.push(Request());
    }
}

/**
 * @brief Adds a Request to the back of the queue.
 *
 * @param req Request The Request object to enqueue.
 */
void RequestQueue::push(Request req) {
    queue.push(req);
}

/**
 * @brief Checks whether the queue is empty.
 *
 * @return bool true if the queue has no requests, false otherwise.
 */
bool RequestQueue::empty() const {
    return queue.empty();
}

/**
 * @brief Removes and returns the Request at the front of the queue.
 *
 * @return Request The Request that was at the front of the queue.
 */
Request RequestQueue::pop() {
    Request frontRequest = queue.front();
    queue.pop();
    return frontRequest;
}

/**
 * @brief Returns the Request at the front of the queue without removing it.
 *
 * @return Request The Request currently at the front of the queue.
 */
Request RequestQueue::peek() {
    Request req = queue.front();
    return req;
}

/**
 * @brief Returns the number of Requests currently in the queue.
 *
 * @return int The current size of the queue.
 */
int RequestQueue::size() const {
    return queue.size();
}