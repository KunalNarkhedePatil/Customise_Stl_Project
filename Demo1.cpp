// #include"list.h"
#include "algorithm.h"
#include<vector>

int main()
{
    algorithm<int> a;
    // list<int> list;

    // list.push_back(10);
    // list.push_back(20);
    // list.push_back(30);
    // list.push_back(40);
    // list.push_back(50);
    // list.push_back(60);

    // list.display();

    int iNo1 = 10;
    int iNo2 = 20;

    a.swap(iNo1, iNo2);

    cout << iNo1 << endl;
    cout << iNo2 << endl;
    cout << a.min(10, 5, 3) << endl;
    cout << a.min(10, 2) << endl;

    vector<int> v={1,2,3,4,5,6};

    cout<<a.min(v);

    return 0;
}
