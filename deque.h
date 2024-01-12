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
//       DEQUE DATA STRUCTURE         //
////////////////////////////////////////

template <class T>
class deque
{
private:
    dequenode<T> *frontp;
    dequenode<T> *rear;
    int isize;
    int maxCapacity;

public:
    deque();
    deque(int maxCapacity);
    ~deque();
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : default constructor
// Description   : It is constructor of deque class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
deque<T>::deque()
{
    this->frontp = NULL;
    this->rear = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of deque class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
deque<T>::deque(int maxCapacity)
{
    this->frontp = NULL;
    this->rear = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : destructor
// Description   : It is destructor of deque class and This function is automatically
//                 called before deallocating the object of class.this function used to
//                 deallocate the resources.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
deque<T>::~deque()
{
    while (!empty())
    {
        pop_front();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is deque and This function is used
//                 to check list empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool deque<T>::empty()
{
    if (this->frontp == NULL && this->rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is deque and This function is used
//                 to size the element  of linked list
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int deque<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is deque and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void deque<T>::display()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return;
    }
    dequenode<T> *temp = frontp;

    for (int i = 1; i <= isize; i++)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : push_front
// Description   : It is deque and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        frontp = newn;
        rear = newn;
    }
    else
    {
        newn->next = frontp;
        frontp->prev = newn;
        frontp = newn;
    }

    rear->next = frontp;
    frontp->prev = rear;
    isize++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is deque and This function is
//                 used to insert the node at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        frontp = newn;
        rear = newn;
    }
    else
    {
        rear->next = newn;
        newn->prev = rear;
        rear = newn;
    }
    rear->next = frontp;
    frontp->prev = rear;
    isize++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : pop_front
// Description   : It is deque and This function is
//                 used to delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_front()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return;
    }
    else if (isize == 1)
    {
        delete frontp;
        frontp = NULL;
        rear = NULL;
    }
    else
    {
        frontp = frontp->next;
        delete rear->next;
        frontp->prev = rear;
        rear->next = frontp;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is deque and This function is
//                 used to delete the node at last position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_back()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return;
    }
    else if (isize == 1)
    {
        delete frontp;
        frontp = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        delete rear->next;
        frontp->prev = rear;
        rear->next = frontp;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : front
// Description   : It is deque and This function is
//                 returns the value of the first element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T deque<T>::front()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return -1;
    }
    return frontp->data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is deque and This function is returns the
//                 value of the last element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : begin
// Description   : It is deque and This function is used to
//                 returns used to first node
// Parameter     :
// Return value  :pointer
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
dequenode<T> *deque<T>::begin()
{
    return frontp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : end
// Description   : It is deque and This function is used to
//                 returns last node pointer
// Parameter     :
// Return value  : pointer
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
dequenode<T> *deque<T>::end()
{
    return rear;
}
