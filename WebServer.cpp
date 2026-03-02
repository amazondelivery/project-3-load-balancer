#include <Request.h>
class WebServer {
private:
    int remainingTime = 0;

public:
    WebServer() {}

    void process(Request req) {
        remainingTime = req.time;
    }

    void tick() {
        if (remainingTime > 0) {
            remainingTime--;
        }
    }

    bool isProcessing() {
        return remainingTime > 0;
    }
};