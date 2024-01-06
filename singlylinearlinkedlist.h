#include <iostream>
using namespace std;
template <class T>
class node // class declaration of singly linked list
{
public:
    T data;
    node<T> *next;

    node(T data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }
};

////////////////////////////////////////
//     SINGLY LINEAR LINKED LIST      //                                        
////////////////////////////////////////

template <class T>
class singlyllist
{
private:
    node<T> *first;
    int isize;
    int maxCapacity;

public:
    singlyllist();
    singlyllist(int maxCapacity);
    ~singlyllist();
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
// Description   : It is constructor of singlyllist class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
singlyllist<T>::singlyllist()
{
    this->first = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of singlyllist class and This function is automatically
//                 called when object of class is created.this function used to initialise
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
singlyllist<T>::singlyllist(int maxCapacity)
{
    this->first = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : destructor
// Description   : It is destructor of singlyllist class and This function is automatically
//                 called before deallocating the object of class.this function used to
//                 deallocate the resources.
// Parameter     :
// Return value  :
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
singlyllist<T>::~singlyllist()
{
    while (!empty())
    {
        deletefirst();
    }
}
////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is Singly Linear Linked list and This function is used
//                 to check the linked list is empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool singlyllist<T>::empty()
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
////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Singly Linear Linked list and This function is used
//                 to display the element of linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::display()
{
    if (empty())
    {
        cout << "linked list is empty\n";
        return;
    }
    node<T> *temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Singly Linear Linked list and This function is used
//                 to size the element of linked list
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int singlyllist<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertfirst
// Description   : It is Singly Linear Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::insertfirst(T val)
{
    if (isize == maxCapacity)
    {
        cout << "linked list is full\n";
        return;
    }
    node<T> *newn = new node<T>(val); // newn = (PNODE)malloc(sizeof(NODE))
                                      // Allocate the memory

    if (empty()) // Linked list is empty
    {
        first = newn;
    }
    else // Linked list contain atleast one node
    {
        newn->next = first;
        first = newn;
    }
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertlast
// Description   : It is Singly Linear Linked list and This function is
//                 used to insert at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::insertlast(T val)
{
    if (isize == maxCapacity)
    {
        cout << "linked list is full\n";
        return;
    }
    node<T> *newn = new node<T>(val); // newn = (PNODE)malloc(sizeof(NODE))
                                      // Allocate the memory

    if (empty())
    {
        first = newn;
    }
    else
    {
        node<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertatpos
// Description   : It is Singly Linear Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and position
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::insertatpos(T val, int ipos)
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
            node<T> *newn = new node<T>(val); // newn = (PNODE)malloc(sizeof(NODE))
            node<T> *temp = first;

            for (register int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
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
// Function Name : deletefirst
// Description   : It is Singly linear Linked list and This function is
//                 used to Delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deletefirst()
{
    if (empty())
    {
        cout << "linked list is empty" << endl;
        return;
    }
    node<T> *temp = first;

    if (first != NULL)
    {
        first = first->next;
        delete temp;

        isize--;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deletelast
// Description   : It is Singly Linear Linked list and This function is
//                 used to Delete the node  at last position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deletelast()
{
    node<T> *temp = first;

    if (empty())
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        isize--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        isize--;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deleteatpos
// Description   : It is Singly Linear Linked list and This function is
//                 used to Delete the node  at perticular position
//                 of Linked list
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deleteatpos(int ipos)
{
    try
    {
        if ((ipos < 0) || (ipos > isize))
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
            node<T> *temp = first;
            node<T> *Targated = NULL;
            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            Targated = temp->next;

            temp->next = Targated->next;
            delete Targated;
            isize--;
        }
    }
    catch (int pos_exception)
    {
        cout << "Exception:invalid position " << pos_exception << endl;
    }
}
