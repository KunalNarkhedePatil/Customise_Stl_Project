#include "deque.h"

int main()
{
    deque<int> obj;

    obj.push_back(10);
    obj.push_back(20);
    obj.push_back(30);
    obj.push_back(40);
    obj.push_back(50);
    obj.push_back(60);
    obj.push_back(70);

    obj.display();
    cout << "size :" << obj.size() << endl;

    obj.push_front(2);
    obj.pop_back();
    obj.pop_front();
    cout << "front :" << obj.front() << endl;
    cout << "back :" << obj.back() << endl;
    obj.pop_back();
    cout << "size :" << obj.size() << endl;

    cout << "begin " << obj.begin() << endl;
    cout << "end " << obj.end() << endl;
    obj.display();

    if (obj.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}