#include"list.h"
#include"vector.h"


int main()
{
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.push_back(60);

    l.display();

    vector<int> v;

    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

    cout<<v.capacity()<<endl;
    return 0;
}
