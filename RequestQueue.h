#include <stdio.h>
#include <Request.h>

class RequestQueue {
    public:
    RequestQueue(int capacity);
    Request pop();
    void push();
    bool empty();
    int size();

};