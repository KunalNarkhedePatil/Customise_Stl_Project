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

    cout << c.size() << endl;

    c.pop();
    c.display();

    if (c.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}