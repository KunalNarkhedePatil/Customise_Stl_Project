#include"doublycircularlinkedlist.h"

int main()
{
    doublyclist<int> lobj;

    lobj.push_back(10);
    lobj.push_back(20);
    lobj.push_back(30);


    lobj.display();

    lobj.push_front(5);

    lobj.display();
    cout<<"size is "<<lobj.size()<<endl;

    lobj.insert(25,3);
    lobj.display();

    lobj.deletenode(3);

    lobj.display();

    cout<<"check whether linkedlist is empty or not"<<endl;

    if(lobj.empty())
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    cout<<"Frist Element:"<<lobj.front()<<endl;
    cout<<"Last Element:"<<lobj.back()<<endl;

    cout<<"First Element Address:"<<lobj.begin()<<endl;
    cout<<"Last Element Address:"<<lobj.end()<<endl;

    //following member are not access becuase its private member

    // cout<<lobj.maxCapacity<<endl;
    // cout<<lobj.first<<endl;
    // cout<<lobj.last<<endl;
    // cout<<lobj.isize<<endl;

    return 0;
}