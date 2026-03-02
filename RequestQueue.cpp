#include <queue>
#include <Request.h>
using namespace std;

class RequestQueue {
public:
    RequestQueue(int capacity) {
        this->capacity = capacity;
    }

    void push(Request req) {
        queue.push(req);
    }

    Request pop() {
        Request frontRequest = queue.front();
        queue.pop();
        return frontRequest;
    }

    int size() {
        return queue.size();
    }

private:
    queue<Request> queue;
    int capacity;
};