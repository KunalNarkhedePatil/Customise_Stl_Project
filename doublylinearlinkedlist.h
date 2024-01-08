#include<iostream>
using namespace std;
template <class T>
class node1 // class declaration of doubly linked list
{
public:
    T data;
    node1<T> *next;
    node1<T> *prev;
    node1(T data) // constructor
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

////////////////////////////////////////
//     DOUBLY LINEAR LINKED LIST      //                                        
////////////////////////////////////////

template <class T>
class doublyllist
{
private:
    node1<T> *first;
    int isize;
    int maxCapacity;

public:
    doublyllist();
    doublyllist(int maxCapacity);
    ~doublyllist();
    int size();
    bool empty();
    void display();
    void insertfirst(T val);
    void insertlast(T val);
    void insertatpos(T val, int ipos);
    void deletefirst();
    void deletelast();
    void deleteatpos(int ipos);
};

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : default constructor
// Description   : It is constructor of doublyllist class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
doublyllist<T>::doublyllist()
{
    this->first = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of doublyllist class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
doublyllist<T>::doublyllist(int maxCapacity)
{

    this->first = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : destructor
// Description   : It is destructor of doublyllist class and This function is automatically
//                 called before deallocating the object of class.this function used to
//                 deallocate the resources.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
doublyllist<T>::~doublyllist()
{
    while (!empty())
    {
        deletefirst();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Doubly Linear Linked list and This function is used
//                 to size the elements of linked list
// Parameter     :
// Return value  : int
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int doublyllist<T>::size()
{
    node1<T> *temp = first;
    int iCnt = 0;
    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}
//we can also use this function for counting the number of nodes in the linked list
/*
template <class T>
int doublyllist<T>::size()
{
    return isize;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is Doubly Linear Linked list and This function is used
//                 to check the linked list is empty or not
// Parameter     :
// Return value  : bool
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool doublyllist<T>::empty()
{
    if (first == NULL)
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
// Function Name : display
// Description   : It is Doubly Linear Linked list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::display()
{
    if (empty())
    {
        cout << "linked list is empty" << endl;
    }
    node1<T> *temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : insertfirst
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::insertfirst(T val)
{
    if (isize == maxCapacity)
    {
        cout << "linked list is full" << endl;
        return;
    }
    node1<T> *newn = new node1<T>(val);

    if (empty())
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }
    isize++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : insertlast
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::insertlast(T val)
{
    if (isize == maxCapacity)
    {
        cout << "linked list is full\n";
        return;
    }
    node1<T> *newn = new node1<T>(val);

    if (isize == 0)
    {
        first = newn;
    }
    else
    {
        node1<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        temp->next->prev = temp;
    }
    isize++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : insertatpos
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and Position
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::insertatpos(T val, int ipos)
{
    try
    {
        if (isize == maxCapacity)
        {
            cout << "linked list is full\n";
            return;
        }
        if ((ipos < 0) || (ipos > isize + 1))
        {
            throw ipos;
        }

        if (ipos == 1)
        {
            insertfirst(val);
        }
        else if (ipos == isize + 1)
        {
            insertlast(val);
        }
        else
        {
            node1<T> *temp = first;

            node1<T> *newn = new node1<T>(val);

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

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : deletefirst
// Description   : It is Doubly linear Linked list and This function is
//                 used to Delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::deletefirst()
{
    node1<T> *temp = first;

    if (empty())
    {
        cout << "linked list is empty" << endl;
        return;
    }
    else if (isize == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete temp;
        first->prev = NULL;
    }
    isize--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : deletelast
// Description   : It is Doubly linear Linked list and This function is
//                 used to Delete the node at last position of Linked list
// Parameter     :
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::deletelast()
{
    node1<T> *temp = first;

    if (empty())
    {
        return;
    }
    else if (isize == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    isize--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : deleteatpos
// Description   : It is Doubly Linear Linked list and This function is
//                 used to Delete the node at perticular position of Linked list
// Parameter     : Position
// Return value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::deleteatpos(int ipos)
{
    try
    {
        if (ipos < 0 || ipos > isize)
        {
            throw ipos;
        }

        if (ipos == 1)
        {
            deletefirst();
        }
        else if (ipos == isize)
        {
            deletelast();
        }
        else
        {
            node1<T> *temp = first;

            for (register int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            node1<T> *Targated = temp->next;
            temp->next = Targated->next;
            delete Targated;
            temp->next->prev = temp;
        }
    }
    catch (int pos_exception)
    {
        cout << "Exception:invalid position " << pos_exception << endl;
    }
}
