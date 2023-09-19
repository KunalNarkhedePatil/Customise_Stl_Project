#include <iostream>
using namespace std;
template <class T>
class dequenode // class declaration of deque(Double Ended Queue)
{
public:
    T data;
    dequenode<T> *next; 

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
    int iSize;

public:
    deque();
    deque(int iSize);
    int size();
    bool empty();
    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    T front();
    T back();
};
template <class T>
deque<T>::deque()
{
    this->front = NULL;
    this->rare = NULL;
    this->isize = 0;
    this->iSize = -1;
}
template <class T>
deque<T>::deque(int iSize)
{
    this->front = NULL;
    this->rare = NULL;
    this->isize = 0;
    this->iSize = iSize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to check deque is empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool deque<T>::empty()
{
    if (this->front == NULL && this->rare == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to return the size of queue
// Parameter     :
// Return value  : int
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
// Parameter     : val
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_front(T val)
{
    dequenode<T> *newn = new dequenode<T>(val);

    if (isize == iSize)
    {
        cout << "deque is full\n";
        return;
    }

    if (empty())
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_back(T val)
{
    if (isize == iSize)
    {
        cout << "deque is full\n";
        return;
    }
    dequenode<T> *newn = new dequenode<T>(val);

    if (empty())
    {
        front = newn;
        rare = newn;
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_front()
{
    if (empty())
    {
        cout << "queue is empty" << endl;
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_back()
{
    dequenode<T> *temp = front;

    if (empty())
    {
        cout << "queue is empty" << endl;
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
        while (temp->next-> != rare)
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
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T deque<T>::front()
{
    return front->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to get the element of back of queue
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T deque<T>::back()
{
    return rare->data;
}
