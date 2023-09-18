#include <iostream>
using namespace std;
///////////////////////////////////
//     VECTOR DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class vector
{
private:
    T *Arr;
    int iCapacity;
    int iCurrent;

public:
    vector();
    ~vector();
    void push_back(T data);
    void push_back(T data, int index);
    void pop_back();
    T at(int index);
    int size();
    void set(int index, T data);
    int capacity();
    void print();
    T operator[](int i);
};
// Default constructor to initialise
// an initial capacity of 1 element and
// allocating storage using dynamic allocation
template <class T>
vector<T>::vector()
{
    this->Arr = new T[1];
    this->iCapacity = 1;
    this->iCurrent = 0;
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data)
{
    // if the number of elements is equal to the
    // capacity, that means we don't have space to
    // add more elements. We need to double the
    // capacity
    if (iCurrent == iCapacity)
    {
        T *temp = new T[2 * iCapacity];
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data, int index)
{
    if (index > iCurrent)
    {
        return;
    }
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
// Return value  : void
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
// Return value  : any data type
//
////////////////////////////////////////////////////////////////////

template <class T>
T vector<T>::at(int index)
{
    // if index is within the range
    if (index < iCurrent)
    {
        return Arr[index];
    }
    throw out_of_range("out of range");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is vector Data Structure and This function is
//                 used to return the size of vector
// Parameter     :
// Return value  : int
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
// Return value  : int
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::print()
{
    for (int i = 0; i < iCurrent; i++)
    {
        cout << Arr[i] << " ";
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
// Return value  : any data type
//
////////////////////////////////////////////////////////////////////

template <class T>
T vector<T>::operator[](int i)
{
    if (i < iCurrent)
    {
        return Arr[i];
    }
    throw out_of_range("out of range");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : set
// Description   : It is vector Data Structure and This function is
//                 used to set or update the data on given index
//                 the data
// Parameter     : index and data
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::set(int index, T data)
{
    if (index > iCurrent)
    {
        Arr[index] = data;
        return;
    }
}