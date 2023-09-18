#include <iostream>
#include <vector>
using namespace std;

template <class T>
class algorithm
{
public:
    const T max(const T val1, const T val2);
    const T max(const T val1, const T val2, const T val3);
    const T max(const vector<T> &array);
    const T min(const T val1, const T val2, const T val3);
    const T min(const T val1, const T val2);
    const T min(const vector<T> &array);
    void swap(T &val1, T &val2);
    void display(vector<T> &arr);
    void display(T arr[],int n);
    int binarysearch(vector<T> &arr, T &key);
    void sort(vector<T> &arr);
    void sort(T arr[],int n);
};

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among two values
// Parameter     :const val1,const val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::max(const T val1, const T val2)
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
// Parameter     :const val1,const val2,const val3
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::max(const T val1, const T val2, const T val3)
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
// Parameter     :const array(reference)
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::max(const vector<T> &array)
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
// Parameter     :const val1,const val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::min(const T val1, const T val2)
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
// Parameter     :const val1,const val2,const val3
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::min(const T val1, const T val2, const T val3)
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
// Parameter     :const array(reference)
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::min(const vector<T> &array)
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
// Parameter     :const val1,const val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::swap(T &val1, T &val2)
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
void algorithm<T>::display(T arr[],int n)
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
int algorithm<T>::binarysearch(vector<T> &Arr, T &Key)
{
    if (Arr.empty())
    {
        return -1;
    }
    int iStart = 0;
    int iEnd = Arr.size() - 1;
    int Mid = iStart + (iEnd - iStart) / 2;
    // int Mid = iStart + (iEnd - iStart) / 2;
    // iStart + iEnd / 2 - iStrat / 2;
    // iStart / 2 + iEnd / 2;
    // (iStart + iEnd) / 2;
    int iFlag = -1;

    while (iStart <= iEnd)
    {
        if (Arr[Mid] == Key)
        {
            iFlag = Mid;
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
        Mid = iStart + (iStart - iEnd) / 2;
    }
    if (iFlag == -1)
    {
        return iFlag;
    }
    else
    {
        return iFlag;
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
void algorithm<T>::sort(T arr[],int n)
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
