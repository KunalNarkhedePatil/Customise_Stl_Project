#include <iostream>
#include "vector.h"
using namespace std;

template <class T>
class algorithm
{
public:
    T max(T val1, T val2);
    T max(T val1, T val2, T val3);
    T max(vector<T> &array);
    T min(T val1, T val2, T val3);
    T min(T val1, T val2);
    T min(vector<T> &array);
    void swap(const T &val1, const T &val2);
    void display(vector<T> &arr);
    void display(T arr[], int n);
    bool binarysearch(vector<T> &arr, const T &key);
    void sort(vector<T> &arr);
    void sort(T arr[], int n);
};

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among two values
// Parameter     :val1,const val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::max(T val1, T val2)
{
    if (val1 > val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among three values
// Parameter     :val1,val2,val3
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::max(T val1, T val2, T val3)
{
    if (val1 > val2 && val1 > val3)
    {
        return val1;
    }
    else if (val2 > val3)
    {
        return val2;
    }
    else
    {
        return val3;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum in vector elements
// Parameter     :array(reference)
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::max(vector<T> &array)
{
    if (array.empty())
    {
        cout << "container is empty\n";
    }

    T maxval = array[0];
    for (const T &val : array)
    { // here we use & as a reference
        if (val > maxval)
        {
            maxval = val;
        }
    }
    return maxval;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum among two values
// Parameter     : val1, val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::min(T val1, T val2)
{
    if (val1 < val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum among three values
// Parameter     : val1,val2,val3
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::min(T val1, T val2, T val3)
{
    if (val1 < val2 && val1 < val3)
    {
        return val1;
    }
    else if (val2 < val3)
    {
        return val2;
    }
    else
    {
        return val3;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum in vector elements
// Parameter     :array(reference)
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::min(vector<T> &array)
{
    if (array.empty())
    {
        cout << "container is empty\n";
    }

    T minval = array[0];
    for (const T &val : array) // here we use & as a reference
    {
        if (val < minval)
        {
            minval = val;
        }
    }
    return minval;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : swap
// Description   : It is algorithm and this function is used swap
//                 two values
// Parameter     :val1,val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::swap(const T &val1, const T &val2)
{
    val1 = val1 + val2;
    val2 = val1 - val2;
    val1 = val1 - val2;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is algorithm and this function is used to display
//                 the content in vector
// Parameter     :vector arr(reference)
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::display(vector<T> &arr)
{
    for (register int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is algorithm and this function is used to display
//                 the content in array
// Parameter     :any type arr,int
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::display(T arr[], int n)
{
    for (register int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is algorithm and this function is used to search
//                 the element inside vector
// Parameter     :any type vector arr(reference),any type key
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
bool algorithm<T>::binarysearch(vector<T> &Arr, const T &Key)
{
    if (Arr.empty())
    {
        cout << "vector is empty\n";
        return false;
    }
    int iStart = 0;
    int iEnd = Arr.size() - 1;
    cout << iEnd << endl;

    bool iFlag = false;
    /*
    int Mid = (iStart + iEnd) / 2;

    New Formula
    int Mid=iStart+(iEnd-iStart)/2;
    iStart+iEnd/2-iStrat/2;
    iStart/2+iEnd/2;
    (iStart+iEnd)/2;
    */

    int Mid = iStart + (iEnd - iStart) / 2;

    while (iStart <= iEnd)
    {
        if (Arr[Mid] == Key)
        {
            iFlag = true;
            break;
        }

        if (Key > Arr[Mid])
        {
            iStart = Mid + 1;
        }
        else if (Key < Arr[Mid])
        {
            iEnd = Mid - 1;
        }
        Mid = iStart + (iEnd - iStart) / 2;
    }
    if (iFlag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : sort
// Description   : It is algorithm and this function is used to sort
//                 the element in vector
// Parameter     :any type vector arr(reference);
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::sort(vector<T> &arr)
{
    int i = 0, j = 0, temp = 0;
    int n = arr.size(); // length of array

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : sort
// Description   : It is algorithm and this function is used to sort
//                 the element in array
// Parameter     :any type arr,int
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::sort(T arr[], int n)
{
    int i = 0, j = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
