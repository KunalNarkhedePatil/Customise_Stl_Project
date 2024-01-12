#include "queue.h"

int main()
{
    queue<char> c;

    c.push('a');
    c.push('b');
    c.push('c');
    c.push('d');
    c.push('e');

    c.display();

    cout << "size of queue is "<<c.size() <<endl;

    c.pop();
    c.display();

    cout<<"Check whether the queue is empty or not"<<endl;

    if (c.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty" << endl;
    }

    return 0;
}