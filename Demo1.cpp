#include "stack.h"

int main()
{
    stack<int> t;

    t.push(10);
    t.push(20);
    t.push(30);
    t.push(40);
    t.push(50);

    t.display();
    return 0;
}