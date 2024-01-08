#include "doublylinearlinkedlist.h"
#include<iostream>
using namespace std;
int main()
{
    doublyllist<float> dobj;

    if(dobj.empty())
    {
        cout<<"linked list is empty"<<endl;;
    }
    else
    {
        cout<<"linked list is not empty"<<endl;
    }

    dobj.insertlast(10.0);
    dobj.insertlast(20.0);
    dobj.insertlast(30.9);
    dobj.insertlast(40.7);
    dobj.insertlast(50.6);

    dobj.display();
    dobj.insertfirst(5.5);

    dobj.display();
    dobj.insertatpos(25.7,3);
    dobj.display();

    dobj.deletefirst();
    dobj.display();

    dobj.deletelast();
    dobj.display();

    dobj.deleteatpos(2);
    dobj.display();



    return 0;
}