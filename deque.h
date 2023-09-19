#include <iostream>
using namespace std;
template <class T>
class dequenode // class declaration of deque
{
public:
    T data;
    dequenode<T> *next;
    dequenode<T> *prev;
    dequenode(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
////////////////////////////////////////
//       DEQUE DATA STRUCTURE          //
////////////////////////////////////////

template <class T>
class deque  
{
private:
    dequenode<T> *front;
    dequenode<T> *rear;
    int isize;
    int maxCapacity;

public:
    deque();
    deque(int maxCapacity);
    bool empty();
    int size();
    void display();
    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    T front();
    T back();
    dequenode<T> *begin();
    dequenode<T> *end();
};

template <class T>
deque<T>::deque()
{
    this->front = NULL;
    this->rear = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}
template <class T>
deque<T>::deque(int maxCapacity)
{
    this->front = NULL;
    this->rear = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is deque and This function is used
//                 to check list empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool deque<T>::empty()
{
    if (this->front == NULL && this->rear == NULL)
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
// Description   : It is deque and This function is used
//                 to size the element  of linked list
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
// Function Name : display
// Description   : It is deque and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void deque<T>::display()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return;
    }
    dequenode<T> *temp = front;

    for (int i = 1; i <= isize; i++)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : push_front
// Description   : It is deque and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_front(T val)
{
    if (isize == maxCapacity)
    {
        cout << "list is full\n";
        return;
    }
    dequenode<T> *newn = new dequenode<T>(val);
    if (empty())
    {
        front = newn;
        rear = newn;
    }
    else
    {
        newn->next = front;
        front->prev = newn;
        front = newn;
    }

    rear->next = front;
    front->prev = rear;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is deque and This function is
//                 used to insert the node at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void deque<T>::push_back(T val)
{
    if (isize == maxCapacity)
    {
        cout << "list is full\n";
        return;
    }
    dequenode<T> *newn = new dequenode<T>(val);

    if (empty())
    {
        front = newn;
        rear = newn;
    }
    else
    {
        rear->next = newn;
        newn->prev = rear;
        rear = newn;
    }
    rear->next = front;
    front->prev = rear;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_front
// Description   : It is deque and This function is
//                 used to delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_front()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return;
    }
    else if (isize==1)
    {
        delete front;
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        delete rear->next;
        front->prev = rear;
        rear->next = front;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is deque and This function is
//                 used to delete the node at last position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_back()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return;
    }
    else if (isize==1)
    {
        delete front;
        front = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        delete rear->next;
        front->prev = rear;
        rear->next = front;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : front
// Description   : It is deque and This function is
//                 returns the value of the first element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T deque<T>::front()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return -1;
    }
    return front->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is deque and This function is returns the
//                 value of the last element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T deque<T>::back()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return -1;
    }
    return rear->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : begin
// Description   : It is deque and This function is used to
//                 returns used to first node
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
dequenode<T> *deque<T>::begin()
{
    return front;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : end
// Description   : It is deque and This function is used to
//                 returns last node pointer
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
dequenode<T> *deque<T>::end()
{
    return rear;
}
