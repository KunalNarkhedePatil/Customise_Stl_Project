//#include "algorithm.h"
#include"stl.h"

int main()
{
    algorithm<int> a;

    int Arr[5]={1,4,7,4,5};

    vector<int> v = {10, 30, 2, 45, 21};

    a.display(Arr,5);
    a.sort(Arr,5);

    a.display(Arr,5);
    return 0;
}