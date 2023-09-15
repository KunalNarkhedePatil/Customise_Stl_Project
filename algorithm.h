#include <iostream>
#include <vector>
using namespace std;

template <class T>
class algorithm
{
public:
    const T max(const T Val1, const T Val2);
    const T max(const T Val1, const T Val2, const T Val3);
    const T max(const vector<T> &array);
    const T min(const T Val1, const T Val2, const T Val3);
    const T min(const T Val1, const T Val2);
    const T min(const vector<T> &array);
    void swap(T &Val1, T &Val2);
};

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among two values
// Parameter     :const Val1,const Val2
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::max(const T Val1, const T Val2)
{
    if (Val1 > Val2)
    {
        return Val1;
    }
    else
    {
        return Val2;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among three values
// Parameter     :const Val1,const Val2,const Val3
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::max(const T Val1, const T Val2, const T Val3)
{
    if (Val1 > Val2 && Val1 > Val3)
    {
        return Val1;
    }
    else if (Val2 > Val3)
    {
        return Val2;
    }
    else
    {
        return Val3;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum in vector elements
// Parameter     :const array(reference)
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::max(const vector<T> &array)
{
    if (array.empty())
    {
        cout << "container is empty\n";
    }

    T maxVal = array[0];
    for (const T &val : array)
    { // here we use & as a reference
        if (val > maxVal)
        {
            maxVal = val;
        }
    }
    return maxVal;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum among two values
// Parameter     :const Val1,const Val2
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::min(const T Val1, const T Val2)
{
    if (Val1 < Val2)
    {
        return Val1;
    }
    else
    {
        return Val2;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum among three values
// Parameter     :const Val1,const Val2,const Val3
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::min(const T Val1, const T Val2, const T Val3)
{
    if (Val1 < Val2 && Val1 < Val3)
    {
        return Val1;
    }
    else if (Val2 < Val3)
    {
        return Val2;
    }
    else
    {
        return Val3;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum in vector elements
// Parameter     :const array(reference)
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
const T algorithm<T>::min(const vector<T> &array)
{
    if (array.empty())
    {
        cout << "container is empty\n";
    }

    T minVal = array[0];
    for (const T &val : array) // here we use & as a reference
    {
        if (val < minVal)
        {
            minVal = val;
        }
    }
    return minVal;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : swap
// Description   : It is algorithm and this function is used swap
//                 two values
// Parameter     :const Val1,const Val2
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::swap(T &Val1, T &Val2)
{
    Val1 = Val1 + Val2;
    Val2 = Val1 - Val2;
    Val1 = Val1 - Val2;
}
