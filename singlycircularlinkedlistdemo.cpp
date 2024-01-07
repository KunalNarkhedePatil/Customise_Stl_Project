#include "singlycircularinkedlist.h"

int main()
{
    singlyclist<int> sobj;

    sobj.insertlast(10);
    sobj.insertlast(20);
    sobj.insertlast(30);
    sobj.insertlast(40);
    sobj.insertlast(50);
    sobj.display();


    sobj.insertfirst(5);
    sobj.display();

    sobj.insertatpos(15,3);
    sobj.display();

    sobj.deletefirst();
    sobj.display();

    sobj.deletelast();
    sobj.display();

    sobj.deleteatpos(2);
    sobj.display();

    sobj.display();

    return 0;
}
/*
Output:-
|10|-> |20|-> |30|-> |40|-> |50|->
|5|-> |10|-> |20|-> |30|-> |40|-> |50|->
|5|-> |10|-> |15|-> |20|-> |30|-> |40|-> |50|->
|10|-> |15|-> |20|-> |30|-> |40|-> |50|->
|10|-> |15|-> |20|-> |30|-> |40|->
|10|-> |20|-> |30|-> |40|->
|10|-> |20|-> |30|-> |40|->
*/