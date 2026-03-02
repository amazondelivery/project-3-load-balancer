#include <queue>
#include <Request.h>
using namespace std;

class RequestQueue {
    public:
    queue<Request> queue;
    int capacity;

    RequestQueue::RequestQueue(int capacity) {
        this->capacity = capacity;
    }

    void RequestQueue::push(Request req) {
        if (queue.size() >= capacity) {

        } else {
            queue.push(req);
        }
    }

    Request RequestQueue::pop() {

    }
};