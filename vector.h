#include<iostream>
using namespace std;
///////////////////////////////////
//     VECTOR DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class vector
{
private:
    int *Arr;
    int iCapacity;
    int iCurrent;

public:
    vector();
    ~vector();
    void push_back(T data);
    void push_back(T data, int index);
    void pop_back();
    int at(int index);
    int size();
    void set(int index, T data);
    int capacity();
    void print();
    int operator[](int i);
};
// Default constructor to initialise
// an initial capacity of 1 element and
// allocating storage using dynamic allocation
template <class T>
vector<T>::vector()
{
    Arr = new int[1];
    iCapacity = 1;
    iCurrent = 0;
}
// destructor to deallocate storage allocated by dynamic allocation
// to prevent memory leak
template <class T>
vector<T>::~vector()
{
    delete[] Arr;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is vector Data Structure and This function is
//                 used to push the element at the last index of vector
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data)
{
    // if the number of elements is equal to the
    // capacity, that means we don't have space to
    // accommodate more elements. We need to double the
    // capacity
    if (iCurrent == iCapacity)
    {
        int *temp = new int[2 * iCapacity];
        // copying old array elements to new array
        for (int i = 0; i < iCapacity; i++)
        {
            temp[i] = Arr[i];
        }
        // deleting previous array
        delete[] Arr;

        iCapacity = iCapacity * 2;
        Arr = temp;
    }
    // Inserting data
    Arr[iCurrent] = data;
    iCurrent++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is vector Data Structure and This function is
//                 used to push the element at the last index of vector
// Parameter     : data and index
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data, int index)
{
    // if index is equal to capacity then this
    // function is same as push defined above
    if (index == iCapacity)
    {
        push_back(data);
    }
    else
    {
        Arr[index] = data;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is vector Data Structure and This function is
//                 used to pop(delete) the element at the last index of vector
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::pop_back()
{
    iCurrent--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : at
// Description   : It is vector Data Structure and This function is
//                 used to return the element at given index
// Parameter     : index
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::at(int index)
{
    // if index is within the range
    if (index < iCurrent)
    {
        return Arr[index];
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is vector Data Structure and This function is
//                 used to return the size of vector
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::size()
{
    return iCurrent;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : capacity
// Description   : It is vector Data Structure and This function is
//                 used to return the current capacity of vector
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::capacity()
{
    return iCapacity;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : print
// Description   : It is vector Data Structure and This function is
//                 used to print the data store in vector
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::print()
{
    for (int i = 0; i < iCurrent; i++)
    {
        printf("%d ", Arr[i]);
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : operator
// Description   : It is vector Data Structure and This function is
//                 used to return the element at gievn index and
//                 this function also overload the [] bracket.
// Parameter     : data
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::operator[](int i)
{
    return Arr[i];
}

////////////////////////////////////////////////////////////////////
//
// Function Name : set
// Description   : It is vector Data Structure and This function is
//                 used to set or update the data on given index
//                 the data
// Parameter     : index and data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::set(int index, T data)
{
    Arr[index] = data;
}