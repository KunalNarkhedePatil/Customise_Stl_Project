//#include <stl.h>
//#include"stl.h"
#include"stack.h"
#include"queue.h"
#include"vector.h"

int main()
{
    stack<int> iobj;
    iobj.push(10);
    iobj.push(20);
    iobj.push(30);
    iobj.push(40);
    iobj.push(50);
    iobj.pop();

    iobj.display();

    ///////////////////////////////////////////////////////

    queue<int> iobj1;

    iobj1.push(10);
    iobj1.push(20);
    iobj1.push(30);
    iobj1.push(40);
    iobj1.push(50);
    iobj1.pop();

    iobj1.display();


    //////////////////////////////////////
    cout<<"----------------------------------------------------------------\n";

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    v.print();
}