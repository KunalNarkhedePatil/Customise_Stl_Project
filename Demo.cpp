#include "stl.h"

int main()
{
    singlyllist<int> obj;

    obj.insertlast(10);
    obj.insertlast(20);
    obj.insertlast(30);
    obj.insertlast(40);
    obj.insertlast(50);
    obj.insertlast(60);

    obj.display();

    obj.deletelast();

    obj.display();
   
    return 0;
}