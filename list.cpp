#include"list.h"

int main()
{
    list<float> fobj;
    fobj.push_back(10.10);
    fobj.push_back(10.20);
    fobj.push_back(10.30);
    fobj.push_back(10.40);
    fobj.push_back(10.50);
    fobj.push_back(10.60);

    fobj.insert(10.44,9);

    fobj.display();



    // list<int> lobj;

    // lobj.push_back(10);
    // lobj.push_back(20);
    // lobj.push_back(30);


    // lobj.display();

    // lobj.push_front(5);

    // lobj.display();
    // cout<<"size is "<<lobj.size()<<endl;

    // lobj.insert(25,3);
    // lobj.display();

    // lobj.deletenode(3);

    // lobj.display();

    // if(lobj.empty())
    // {
    //     cout<<"true"<<endl;
    // }
    // else
    // {
    //     cout<<"false"<<endl;
    // }

    // cout<<lobj.front()<<endl;
    // cout<<lobj.back()<<endl;

    // cout<<lobj.begin()<<endl;
    // cout<<lobj.end()<<endl;

    //cout<<lobj.maxCapacity<<endl;
    // cout<<lobj.first<<endl;
    // cout<<lobj.last<<endl;
    // cout<<lobj.isize<<endl;

    return 0;
}