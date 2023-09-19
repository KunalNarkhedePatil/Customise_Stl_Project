#include <iostream>
using namespace std;
template <class T>
class queuenode // class declaration of queue
{
public:
    T data;
    queuenode<T> *next;

    queuenode(T val)
    {
        this->data = val;
        this->next = NULL;
    }
};

///////////////////////////////////
//      QUEUE DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class queue
{
private:
    queuenode<T> *front;
    queuenode<T> *rare;
    int isize;
    int maxCapacity;

public:
    queue();
    queue(int maxCapacity);
    bool empty();
    void display();
    int size();
    void push(T val);
    void pop();
};

template <class T>
queue<T>::queue()
{
    this->front = NULL;
    this->rare = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}
template <class T>
queue<T>::queue(int maxCapacity)
{
    this->front = NULL;
    this->rare = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Queue Data Structure and This function is used
//                 to display the element  of queue
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::display()
{
    queuenode<T> *temp = front;

    if (empty())
    {
        cout << "queue is empty" << endl;
        return;
    }

    do
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    } while (temp != rare->next);
    cout << "NULL" << endl;

    cout << endl;
}
template <class T>
bool queue<T>::empty()
{
    if (front == NULL && rare == NULL)
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
// Description   : It is Queue Data Structure and This function is used
//                 to size the element  of queue
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int queue<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push
// Description   : It is Queue Data Structure and This function is
//                 used to push(insert) the element into queue
// Parameter     : data
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::push(T val) // insertlast
{
    if (isize == maxCapacity)
    {
        cout << "Queue is full\n";
        return;
    }
    queuenode<T> *newn = new queuenode<T>(val);

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
// Function Name : pop
// Description   : It is Queue Data Structure and This function is
//                 used to pop(remove) the element into stack
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::pop() // deletefirst
{
    if (empty())
    {
        cout << "queue is empty" << endl;
        return;
    }
    else if (isize == 1)
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
