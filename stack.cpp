#include "stack.h"

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.display();

    s.pop();
    s.pop();

    s.display();

    cout << "top:" << s.top() << endl;
    cout << "size:" << s.size() << endl;

    // cout<<s.first<<endl;
    // cout<<s.last<<endl;

    // cout<<s.maxCapacity<<endl;

    if (s.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    //creating a stack for float 

    stack<float> s1(5);

    s1.push(1.1);
    s1.push(1.2);
    s1.push(1.3);
    s1.push(1.4);
    s1.push(1.5);

    s1.display();

    s1.pop();
    s1.pop();
    s1.pop();

    s1.display();

    return 0;
}