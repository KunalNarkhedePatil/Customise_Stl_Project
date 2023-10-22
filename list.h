#include <iostream>
using namespace std;
template <class T>
class node1 // class declaration of list
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
//       LIST DATA STRUCTURE          //
////////////////////////////////////////

template <class T>
class list
{
private:
    node1<T> *first;
    node1<T> *last;
    int isize;
    int maxCapacity;

public:
    list();
    list(int maxCapacity);
    ~list();
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
// Description   : It is constructor of list class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
list<T>::list() // default constructor list class
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of list class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
list<T>::list(int maxCapacity)
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
list<T>::~list()
{
    while (!empty())
    {
        pop_front();
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is list and This function is used
//                 to check list empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool list<T>::empty()
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
// Description   : It is list and This function is used
//                 to size the element  of linked list
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int list<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void list<T>::display()
{
    if (empty())
    {
        cout << "list is empty" << endl;
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
// Description   : It is list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::push_front(T val)
{
    if (isize == maxCapacity)
    {
        cout << "list is full\n";
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
// Description   : It is list and This function is
//                 used to insert the node at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void list<T>::push_back(T val)
{
    if (isize == maxCapacity)
    {
        cout << "list is full\n";
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
// Description   : It is list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and position
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::insert(T val, int ipos)
{
    try
    {
        if (isize == maxCapacity)
        {
            cout << "list is full\n";
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
// Description   : It is list and This function is
//                 used to delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::pop_front()
{
    if (empty())
    {
        cout << "list is empty" << endl;
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
// Description   : It is list and This function is
//                 used to Delete the node at last position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::pop_back()
{
    if (empty())
    {
        cout << "list is empty" << endl;
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
// Description   : It is list and this function is
//                 used to delete at perticular position of Linked list
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::deletenode(int ipos)
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
// Description   : It is list and this function is
//                 returns the value of the first element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T list<T>::front()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return -1;
    }
    return first->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is list and this function is returns the
//                 value of the last element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T list<T>::back()
{
    if (empty())
    {
        cout << "list is empty" << endl;
        return -1;
    }
    return last->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : begin
// Description   : It is list and This function is used to
//                 returns used to first node
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
node1<T> *list<T>::begin()
{
    return first;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : end
// Description   : It is list and This function is used to
//                 returns last node pointer
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
node1<T> *list<T>::end()
{
    return last;
}
