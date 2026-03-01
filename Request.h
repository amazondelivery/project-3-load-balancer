#include <string>
using namespace std;

class Request {
    public:
    Request();

    private:
    string generateRandomIP();
    int generateRandomTime();
};