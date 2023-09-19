#include "stack.h"

int main()
{
    stack<int> s;

    
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);

    s.display();

    cout<<s.size()<<endl;

    s.pop();
    s.pop();

    cout<<s.size()<<endl;
    
    return 0;
}