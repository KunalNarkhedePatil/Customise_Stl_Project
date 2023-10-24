#include<iostream>
using namespace std;

class Demo
{
    public:

    int *Arr;
    int current;
    int capacity;

    Demo()
    {
        Arr=new int[1];
        current=0;
        capacity=1;
    }

    void insert(int val)
    {
        if(current==capacity)
        {
            int *temp=new int[2*capacity];

            for(int i=0;i<capacity;i++)
            {
                temp[i]=Arr[i];
            }

            delete []Arr;

            capacity=2* capacity;

            Arr=temp;
        }
        Arr[current]=val;
        current++;
    }
    void insertIndex(int ind,int data)
    {
        if(ind<0 || ind>current)
        {
            return;
        }
        if(ind==current)
        {
            insert(data);
        }
        else
        {
            Arr[ind]=data;
        }
    }
    void display()
    {
        for(int i=0;i<current;i++)
        {
            cout<<Arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Demo obj;

    obj.insert(10);
    obj.insert(20);
    obj.insert(10);
    obj.insert(30);
    obj.insert(40);

    obj.insertIndex(3,23);

    obj.display();
    return 0;
}