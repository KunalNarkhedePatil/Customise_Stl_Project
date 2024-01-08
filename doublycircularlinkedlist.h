#include <iostream>
using namespace std;
template <class T>
class node1 // class declaration of doublyclist
{
public:
    T data;
    node1<T> *next;
    node1<T> *prev;
    node1(T data) // paremeterised constructor node1 class
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
////////////////////////////////////////
//   DOUBLY CIRCULAR DATA STRUCTURE   //
////////////////////////////////////////

template <class T>
class doublyclist
{
private:
    node1<T> *first;
    node1<T> *last;
    int isize;
    int maxCapacity;

public:
    doublyclist();
    doublyclist(int maxCapacity);
    ~doublyclist();
    bool empty();
    int size();
    void display();
    void push_front(T val);
    void push_back(T val);
    void insert(T val, int ipos);
    void pop_front();
    void pop_back();
    void deletenode(int ipos);
    T front();
    T back();
    node1<T> *begin();
    node1<T> *end();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : default constructor
// Description   : It is constructor of doublyclist class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
doublyclist<T>::doublyclist() // default constructor doublyclist class
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of doublyclist class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
doublyclist<T>::doublyclist(int maxCapacity)
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : destructor
// Description   : It is destructor of stack class and This function is automatically
//                 called before deallocating the object of class.this function used to
//                 deallocate the resources.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
doublyclist<T>::~doublyclist()
{
    while (!empty())
    {
        pop_front();
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is doublyclist and This function is used
//                 to check doublyclist empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool doublyclist<T>::empty()
{
    if (this->first == NULL && this->last == NULL)
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
// Description   : It is doublyclist and This function is used
//                 to size the element  of linked doublyclist
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int doublyclist<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is doublyclist and This function is used
//                 to display the element  of linked doublyclist
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyclist<T>::display()
{
    if (empty())
    {
        cout << "doublyclist is empty" << endl;
        return;
    }
    node1<T> *temp = first;

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
// Description   : It is doublyclist and This function is
//                 used to insert at first position of Linked doublyclist
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::push_front(T val)
{
    if (isize == maxCapacity)
    {
        cout << "doublyclist is full\n";
        return;
    }
    node1<T> *newn = new node1<T>(val);
    if (empty())
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is doublyclist and This function is
//                 used to insert the node at last position of Linked doublyclist
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyclist<T>::push_back(T val)
{
    if (isize == maxCapacity)
    {
        cout << "doublyclist is full\n";
        return;
    }
    node1<T> *newn = new node1<T>(val);

    if (empty())
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insert
// Description   : It is doublyclist and This function is
//                 used to insert at perticular position of Linked doublyclist
// Parameter     : Data of node and position
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::insert(T val, int ipos)
{
    try
    {
        if (isize == maxCapacity)
        {
            cout << "doublyclist is full\n";
            return;
        }

        if ((ipos < 0) || (ipos > isize + 1))
        {
            throw ipos;
        }
        if (ipos == 1)
        {
            push_front(val);
        }
        else if (ipos == isize + 1)
        {
            push_back(val);
        }
        else
        {
            node1<T> *newn = new node1<T>(val);

            node1<T> *temp = first;

            for (register int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            newn->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
            isize++;
        }
    }
    catch (int pos_exception)
    {
        cout << "Exception:invalid position " << pos_exception << endl;
    }
}
////////////////////////////////////////////////////////////////////
//
// Function Name : pop_front
// Description   : It is doublyclist and This function is
//                 used to delete the node at first position of Linked doublyclist
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::pop_front()
{
    if (empty())
    {
        cout << "doublyclist is empty" << endl;
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is doublyclist and This function is
//                 used to Delete the node at last position of Linked doublyclist
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::pop_back()
{
    if (empty())
    {
        cout << "doublyclist is empty" << endl;
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deletenode
// Description   : It is doublyclist and this function is
//                 used to delete at perticular position of Linked doublyclist
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::deletenode(int ipos)
{
    try
    {
        if ((ipos < 0) || (ipos > isize))
        {
            throw ipos;
        }
        if (ipos == 1)
        {
            pop_front();
        }
        else if (ipos == isize)
        {
            pop_back();
        }
        else
        {
            node1<T> *temp = first;

            for (register int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

            isize--;
        }
    }
    catch (int pos_exception)
    {
        cout << "Exception:invalid position " << pos_exception <<endl;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : front
// Description   : It is doublyclist and this function is
//                 returns the value of the first element in the doublyclist.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T doublyclist<T>::front()
{
    if (empty())
    {
        cout << "doublyclist is empty" << endl;
        return -1;
    }
    return first->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is doublyclist and this function is returns the
//                 value of the last element in the doublyclist.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T doublyclist<T>::back()
{
    if (empty())
    {
        cout << "doublyclist is empty" << endl;
        return -1;
    }
    return last->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : begin
// Description   : It is doublyclist and This function is used to
//                 returns used to first node
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
node1<T> *doublyclist<T>::begin()
{
    return first;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : end
// Description   : It is doublyclist and This function is used to
//                 returns last node pointer
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
node1<T> *doublyclist<T>::end()
{
    return last;
}
