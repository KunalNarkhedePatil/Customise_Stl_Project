#include"list.h"

int main()
{
    list<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);
    list.push_back(60);

    list.display();
    return 0;
}