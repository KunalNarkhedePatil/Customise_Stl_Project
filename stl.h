#include <iostream>
#include <vector>
using namespace std;
template <class T>
class node // class declaration of singly linked list
{
public:
    T data;
    node<T> *next;

    node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class node1 // class declaration of doubly linked list
{
public:
    T data;
    node1<T> *next;
    node1<T> *prev;
    node1(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class stacknode // class declaration of stack
{
public:
    T data;
    stacknode<T> *next;

    stacknode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
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

////////////////////////////////////////
//     SINGLY LINEAR LINKED LIST      //                                        //
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
template <class T>
singlyllist<T>::singlyllist()
{
    this->first = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

template <class T>
singlyllist<T>::singlyllist(int maxCapacity)
{
    this->first = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
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
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
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
    if (isize == maxCapacity)
    {
        cout << "linked list is full\n";
        return;
    }
    if ((ipos < 0) || (ipos > isize + 1))
    {
        cout << "Invalid Position" << endl;
        return;
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
//                 used to Delete the node  at perticular position of Linked list
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deleteatpos(int ipos)
{

    if ((ipos < 0) || (ipos > isize))
    {
        cout << "Invalid Position" << endl;
        return;
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

////////////////////////////////////////
//     SINGLY CIRCULAR LINKED LIST    //                                        //
////////////////////////////////////////
template <class T>
class singlyclist
{
private:
    node<T> *first;
    node<T> *last;
    int isize;
    int maxCapacity;

public:
    singlyclist();
    singlyclist(int maxCapacity);
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

template <class T>
singlyclist<T>::singlyclist()
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity=-1;
}

template <class T>
singlyclist<T>::singlyclist(int maxCapacity)
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity=maxCapacity;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is Singly Circular Linked list and This function is used
//                 to check the linked list is empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool singlyclist<T>::empty()
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
// Function Name : display
// Description   : It is Singly Circular Linked list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::display()
{
    if (empty())
    {
        cout << "linked list is empty\n";
        return;
    }
    node<T> *temp = first;
    do
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    } while (temp != last->next);
    printf("NULL");

    cout << "\n";
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Singly Circular Linked list and This function is used
//                 to size the element of linked list
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int singlyclist<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertfirst
// Description   : It is Singly Circular Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::insertfirst(T val)
{
    if(isize==maxCapacity)
    {
        cout<<"linked list is full"<<endl;
        returnl
    }
    node<T> *newn = new node<T>(val);

    if (empty())
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    last->next = first;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertlast
// Description   : It is Singly Circular Linked list and This function is
//                 used to insert at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void singlyclist<T>::insertlast(T val)
{
    
    if(isize==maxCapacity)
    {
        cout<<"linked list is full"<<endl;
        returnl
    }
    node<T> *newn = new node<T>(val);

    if (empty())
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertatpos
// Description   : It is Singly Circular Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and position
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::insertatpos(T val, int ipos)
{
    if(isize==maxCapacity)
    {
        cout<<"linked list is full"<<endl;
        returnl
    }
    if ((ipos < 0) || (ipos > (isize + 1)))
    {
        cout << "Invalid position" << endl;
        return;
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
        node<T> *newn = new node<T>(val);
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

////////////////////////////////////////////////////////////////////
//
// Function Name : deletefirst
// Description   : It is Singly Circular Linked list and This function is
//                 used to Delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void singlyclist<T>::deletefirst()
{
    if (empty())
    {
        cout << "linked list is empty" << endl;
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
        node<T> *temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deletelast
// Description   : It is Singly Circular Linked list and This function is
//                 used to Delete the node at last position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::deletelast()
{

    if (empty())
    {
        cout << "linked list is empty" << endl;
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
        node<T> *temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deleteatpos
// Description   : It is Singly Circular Linked list and This function is
//                 used to Delete the node at perticular position of Linked list
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::deleteatpos(int ipos)
{
    if ((ipos < 1) || (ipos > isize))
    {
        cout << "Invalid position" << endl;
        return;
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
        for (register int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        node<T> *Targated = temp->next;

        temp->next = Targated->next; // temp->next = temp->next->next;
        delete Targated;

        isize--;
    }
}

////////////////////////////////////////
//     DOUBLY LINEAR LINKED LIST      //                                        //
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
template <class T>
doublyllist<T>::doublyllist()
{
    thid->first = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}
template <class T>
doublyllist<T>::doublyllist(int maxCapacity)
{

    thid->first = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Doubly Linear Linked list and This function is used
//                 to size the elements of linked list
// Parameter     :
// Return value  : int
//
////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is Doubly Linear Linked list and This function is used
//                 to check the linked list is empty or not
// Parameter     :
// Return value  : bool
//
////////////////////////////////////////////////////////////////////

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
////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Doubly Linear Linked list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////
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
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertfirst
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::insertfirst(T val)
{
    if (isize == iSize)
    {
        cout << "linked list is full\n";
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

////////////////////////////////////////////////////////////////////
//
// Function Name : insertlast
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at last position of Linked list
// Parameter     : Data of node
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::insertlast(T val)
{
    if (isize == iSize)
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

////////////////////////////////////////////////////////////////////
//
// Function Name : insertatpos
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::insertatpos(T val, int ipos)
{
    if (isize == maxCapacity)
    {
        cout << "linked list is full\n";
        return;
    }
    if ((ipos < 0) || (ipos > isize + 1))
    {
        return;
    }

    if (ipos == 1)
    {
        insertfirst(val);
    }
    else if (ipos == size + 1)
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

////////////////////////////////////////////////////////////////////
//
// Function Name : deletefirst
// Description   : It is Doubly linear Linked list and This function is
//                 used to Delete the node at first position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////
//
// Function Name : deletelast
// Description   : It is Doubly linear Linked list and This function is
//                 used to Delete the node at last position of Linked list
// Parameter     :
// Return value  : void
//
////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////
//
// Function Name : deleteatpos
// Description   : It is Doubly Linear Linked list and This function is
//                 used to Delete the node at perticular position of Linked list
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::deleteatpos(int ipos)
{
    if (ipos < 0 || ipos > isize)
    {
        return;
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
        node<T> *Targated = temp->next;
        temp->next = Targated->next;
        delete Targated;
        temp->next->prev = temp;
    }
}

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

template <class T>
list<T>::list()
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}
template <class T>
list<T>::list(int maxCapacity)
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
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
    printf("NULL");
    cout << "\n";
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
    if (isize == maxCapacity)
    {
        cout << "list is full\n";
        return;
    }
    if ((ipos < 0) || (ipos > isize + 1))
    {
        cout << "Invalid position\n";
        return;
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

        newn->data = val;
        newn->next = NULL;
        newn->prev = NULL;

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
////////////////////////////////////////////////////////////////////
//
// Function Name : pop_front
// Description   : It is list and This function is
//                 used to Delete the node at first position of Linked list
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
// Description   : It is and This function is
//                 used to Delete at perticular position of Linked list
// Parameter     : Position
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::deletenode(int ipos)
{
    if ((ipos < 0) || (ipos > isize))
    {
        cout<<"Invalid position"<<endl;
        return;
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

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        isize--;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : front
// Description   : It is list and This function is
//                 returns the value of the first element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T list<T>::front()
{
    if(empty())
    {
        cout<<"list is empty"<<endl;
        return -1;
    }
    return first->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is list and This function is returns the 
//                 value of the last element in the list.
// Parameter     :
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T list<T>::back()
{
    if(empty())
    {
        cout<<"list is empty"<<endl;
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

///////////////////////////////////
//      STACK DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class stack
{
private:
    stacknode<T> *first;
    stacknode<T> *last;
    int isize;
    int maxCapacity;

public:
    stack();
    stack(int maxCapacity);
    bool empty();
    T top();
    void display();
    int size();
    void push(T Val);
    void pop();
};
template <class T>
stack<T>::stack(int maxCapacity)
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
}
template <class T>
stack<T>::stack()
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is stack Data Structure and This function is used
//                 to check stack is empty or not
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
bool stack<T>::empty()
{
    if (first == NULL && last == NULL)
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
// Description   : It is stack Data Structure and This function is used
//                 to display the element of stack
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::display()
{
    stacknode<T> *temp = first;

    if (empty())
    {
        cout << "stack is empty" << endl;
        return;
    }

    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != last->next);
    cout << "NULL" << endl;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : top
// Description   : It is stack Data Structure and This function is used
//                 to return the top element in stack
// Parameter     :
// Return Value  : any datatype
//
////////////////////////////////////////////////////////////////////

template <class T>
T stack<T>::top()
{
    if (empty())
    {
        cout << "stack is empty\n";
        return -1;
    }
    return last->data;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is stack Data Structure and This function is used
//                 to size the element of linked list
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int stack<T>::size()
{
    return isize;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push
// Description   : It is stack Data Structure and This function is
//                 used to push(insert) the element into stack
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::push(T Val)
{
    stacknode<T> *newn = new stacknode<T>(Val);

    if (isize == maxCapacity)
    {
        cout << "Stack is full\n";
        return;
    }

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;
    isize++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop
// Description   : It is stack Data Structure and This function is
//                 used to pop(remove) the element into stack
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::pop()
{
    stacknode<T> *temp = first;

    if (empty())
    {
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
        while (temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    isize--;
}
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
    int iSize;

public:
    queue();
    queue(int iSize);
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
    this->iSize = -1;
}
template <class T>
queue<T>::queue(int iSize)
{
    this->front = NULL;
    this->rare = NULL;
    this->isize = 0;
    this->iSize = iSize;
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
    if (isize == iSize)
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
    int maxCapacity;

public:
    deque();
    deque(int maxCapacity);
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
    this->maxCapacity = -1;
}
template <class T>
deque<T>::deque(int iSize)
{
    this->front = NULL;
    this->rare = NULL;
    this->isize = 0;
    this->maxCapacity = maxCapacity;
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

    if (isize == maxCapacity)
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
    if (isize == maxCapacity)
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

//////////////////////
//     ALGORITHM    //
//////////////////////

template <class T>
class algorithm
{
public:
    T max(T val1, T val2);
    T max(T val1, T val2, T val3);
    T max(vector<T> &array);
    T min(T val1, T val2, T val3);
    T min(T val1, T val2);
    T min(vector<T> &array);
    void swap(const T &val1, const T &val2);
    void display(vector<T> &arr);
    void display(T arr[], int n);
    bool binarysearch(vector<T> &arr, const T &key);
    void sort(vector<T> &arr);
    void sort(T arr[], int n);
};

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among two values
// Parameter     :val1,const val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::max(T val1, T val2)
{
    if (val1 > val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum among three values
// Parameter     :val1,val2,val3
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::max(T val1, T val2, T val3)
{
    if (val1 > val2 && val1 > val3)
    {
        return val1;
    }
    else if (val2 > val3)
    {
        return val2;
    }
    else
    {
        return val3;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : max
// Description   : It is algorithm and this function is used find
//                 maximum in vector elements
// Parameter     :rray(reference)
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::max(vector<T> &array)
{
    if (array.empty())
    {
        cout << "container is empty\n";
    }

    T maxval = array[0];
    for (const T &val : array)
    { // here we use & as a reference
        if (val > maxval)
        {
            maxval = val;
        }
    }
    return maxval;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum among two values
// Parameter     : val1, val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::min(T val1, T val2)
{
    if (val1 < val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum among three values
// Parameter     : val1,val2,val3
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::min(T val1, T val2, T val3)
{
    if (val1 < val2 && val1 < val3)
    {
        return val1;
    }
    else if (val2 < val3)
    {
        return val2;
    }
    else
    {
        return val3;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : min
// Description   : It is algorithm and this function is used find
//                 minimum in vector elements
// Parameter     :array(reference)
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T algorithm<T>::min(vector<T> &array)
{
    if (array.empty())
    {
        cout << "container is empty\n";
    }

    T minval = array[0];
    for (const T &val : array) // here we use & as a reference
    {
        if (val < minval)
        {
            minval = val;
        }
    }
    return minval;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : swap
// Description   : It is algorithm and this function is used swap
//                 two values
// Parameter     :val1,val2
// Return value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::swap(const T &val1, const T &val2)
{
    val1 = val1 + val2;
    val2 = val1 - val2;
    val1 = val1 - val2;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is algorithm and this function is used to display
//                 the content in vector
// Parameter     :vector arr(reference)
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::display(vector<T> &arr)
{
    for (register int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is algorithm and this function is used to display
//                 the content in array
// Parameter     :any type arr,int
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::display(T arr[], int n)
{
    for (register int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is algorithm and this function is used to search
//                 the element inside vector
// Parameter     :any type vector arr(reference),any type key
// Return value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
bool algorithm<T>::binarysearch(vector<T> &Arr, const T &Key)
{
    if (Arr.empty())
    {
        cout << "vector is empty\n";
        return false;
    }
    int iStart = 0;
    int iEnd = Arr.size() - 1;
    cout << iEnd << endl;

    bool iFlag = false;
    /*
    int Mid = (iStart + iEnd) / 2;

    New Formula
    int Mid=iStart+(iEnd-iStart)/2;
    iStart+iEnd/2-iStrat/2;
    iStart/2+iEnd/2;
    (iStart+iEnd)/2;
    */

    int Mid = iStart + (iEnd - iStart) / 2;

    while (iStart <= iEnd)
    {
        if (Arr[Mid] == Key)
        {
            iFlag = true;
            break;
        }

        if (Key > Arr[Mid])
        {
            iStart = Mid + 1;
        }
        else if (Key < Arr[Mid])
        {
            iEnd = Mid - 1;
        }
        Mid = iStart + (iEnd - iStart) / 2;
    }
    if (iFlag == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : sort
// Description   : It is algorithm and this function is used to sort
//                 the element in vector
// Parameter     :any type vector arr(reference);
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::sort(vector<T> &arr)
{
    int i = 0, j = 0, temp = 0;
    int n = arr.size(); // length of array

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : sort
// Description   : It is algorithm and this function is used to sort
//                 the element in array
// Parameter     :any type arr,int
// Return value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void algorithm<T>::sort(T arr[], int n)
{
    int i = 0, j = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
