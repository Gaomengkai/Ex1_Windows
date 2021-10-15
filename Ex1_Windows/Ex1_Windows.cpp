#include "Ex1.h"
extern const char* TestQueue(int& s);
int main()
{
    const char* e;
    int s;
    e = TestQueue(s);
    printf("%s\n%d", e, s);
}