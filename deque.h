#include <iostream>
using namespace std;
template <class T>
class dequenode // class declaration of deque(Double Ended Queue)
{
public:
    T data;
    class dequenode<T> *next;

    dequenode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
///////////////////////////////////
//      DEQUE DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class deque
{
private:
    dequenode<T> *front;
    dequenode<T> *rare;
    int isize;

public:
    deque();
    int size();
    void push_front(T);
    void push_back(T);
    void pop_front();
    void pop_back();
    int front();
    int back();
};
template <class T>
deque<T>::deque()
{
    front = NULL;
    rare = NULL;
    isize = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to return the size of queue
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int deque<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_front
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to push(insert) at front of queue
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_front(T val)
{
    dequenode<T> *newn = new dequenode<T>(val);

    newn->data = val;
    newn->next = NULL;

    if ((front == NULL) && (rare == NULL))
    {
        front = newn;
        rare = newn;
    }
    else
    {
        newn->next = front;
        front = newn;
    }

    rare->next = front;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to push(insert) at back of queue
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_back(T val)
{
    dequenode<T> *newn = new dequenode<T>(val);

    newn->data = no;
    newn->next = NULL;

    if ((front == NULL) && (rare == NULL))
    {
    }
    else
    {
        rare->next = newn;
        rare = newn;
    }

    rare->next = front;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_front
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to pop(remove) at front of queue
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_front()
{
    if ((front == NULL) && (rare == NULL))
    {
        return;
    }
    else if (front == rare)
    {
        delete front;
        front = NULL;
        rare = NULL;
    }
    else
    {
        front = front->next;
        delete rare->next;
        rare->next = front;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to pop(remove) at back of queue
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_back()
{
    dequenode<T> *temp = front;

    if ((front == NULL) && (rare == NULL))
    {
        return;
    }
    else if (front == rare)
    {
        delete front;
        front = NULL;
        rare = NULL;
    }
    else
    {
        while (temp->next != rare)
        {
            temp = temp->next;
        }

        delete rare;
        rare = temp;

        rare->next = front;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : front
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to get the element of front of queue
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
int deque<T>::front()
{
    return front->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to get the element of back of queue
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
int deque<T>::back()
{
    return rare->data;
}
