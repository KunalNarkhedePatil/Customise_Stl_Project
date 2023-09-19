#include "algorithm.h"

int main()
{
    algorithm<int> a;

     vector<int> v={10,20,3,4,5,3};
    // int iret=a.max(v);
    // cout<<iret<<endl;

    int iNo1=2;
    int iNo2=3;

    cout<<a.min(iNo1,iNo2)<<endl;

    int iNo=5;
    if(a.binarysearch(v,300)==false)
    {
        cout<<"element is not present"<<endl;
    }
    else
    {
        cout<<"element is prsent"<<endl;
    }
    return 0;
}