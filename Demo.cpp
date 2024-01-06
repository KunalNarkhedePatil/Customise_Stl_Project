#include "singlylinearlinkedlist.h"

int main()
{
    singlyllist<int> sobj;

    sobj.insertlast(10);
    sobj.insertlast(20);
    sobj.insertlast(30);
    sobj.insertlast(40);
    sobj.insertlast(50);

    sobj.display();

}

/*
Output:-
|10|-> |20|-> |30|-> |40|-> |50|-> NULL
*/

