#include "Ex1.h"
extern const char* TestQueue(int& s);
int main()
{
    const char* e;
    int s;
    e = TestQueue(s);
    std::cout << s;
    std::cout << e;
}