#include <queue>
#include <Request.h>
using namespace std;

class RequestQueue {
public:
    RequestQueue(int size) {
        for (int i = 0; i < size; i++) {
            queue.push(Request());
        }
    }

    void push(Request req) {
        queue.push(req);
    }

    bool empty() {
        return queue.empty();
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
};