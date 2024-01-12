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
    queuenode<T> *rear;
    int isize;
    int maxCapacity;

public:
    queue();
    queue(int maxCapacity);
    ~queue();
    bool empty();
    void display();
    int size();
    void push(T val);
    void pop();
};
///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : default constructor
// Description   : It is constructor of queue class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
queue<T>::queue()
{
    this->front = NULL;
    this->rear = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of queue class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
queue<T>::queue(int maxCapacity)
{
    this->front = NULL;
    this->rear = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : destructor
// Description   : It is destructor of queue class and This function is automatically
//                 called before deallocating the object of class.this function used to
//                 deallocate the resources.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
queue<T>::~queue()
{
    while (!empty())
    {
        pop();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Queue Data Structure and This function is used
//                 to display the element  of queue
// Parameter     :
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

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
    } while (temp != rear->next);
    cout << "NULL" << endl;

    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is Queue Data Structure and This function is used
//                 to check queue is empty or not
// Parameter     :
// Return value  : bool
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool queue<T>::empty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Queue Data Structure and This function is used
//                 to size the element  of queue
// Parameter     :
// Return value  : int
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int queue<T>::size()
{
    return isize;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : push
// Description   : It is Queue Data Structure and This function is
//                 used to push(insert) the element into queue
// Parameter     : data
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::push(T val) // insertlast
{
    if (isize == maxCapacity)
    {
        cout << "queue is full\n";
        return;
    }
    queuenode<T> *newn = new queuenode<T>(val);

    if (empty())
    {
        front = newn;
        rear = newn;
    }
    else
    {
        rear->next = newn;
        rear = newn;
    }

    rear->next = front;
    isize++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : pop
// Description   : It is Queue Data Structure and This function is
//                 used to pop(remove) the element into stack
// Parameter     :
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

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
        rear = NULL;
    }
    else
    {
        front = front->next;
        delete rear->next;
        rear->next = front;
    }
    isize--;
}
