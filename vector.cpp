#include"vector.h"

int main()
{
    vector<int> i;

    cout<<"size of vector is "<<sizeof(i)<<endl;
    vector<float> f;
    vector<double> d;
    vector<char> c;

    i.push_back(10);
    i.push_back(20);
    i.push_back(30);

    cout<<"element is "<<i[7]<<endl;

    i.print();


    f.push_back(10.10);
    f.push_back(10.20);
    f.push_back(10.30);

    f.print();

    
    d.push_back(10.10);
    d.push_back(10.20);
    d.push_back(10.30);

    d.print();

    c.push_back('a');
    c.push_back('b');
    c.push_back('c');

    c.print();

    return 0;
}
