#include <iostream>
using namespace std;
template <class T>
struct node // Structure declaration of singly linked list
{
    T data;
    node<T> *next;
};

template <class T>
struct node1 // Structure declaration of doubly linked list
{
    T data;
    struct node1 *next;
    struct node1 *prev;
};

template <class T>
struct stacknode // Structure declaration of stack
{
    T data;
    stacknode<T> *next;
};

template <class T>
struct Queuenode // Structure declaration of queue
{
    T data;
    struct Queuenode *next;
};

template <class T>
struct dequenode // Structure declaration of deque(Double Ended Queue)
{
    T data;
    dequenode<T> *next;
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

public:
    singlyllist();
    int size();
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
    first = NULL;
    isize = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Singly Linear Linked list and This function is used
//                 to display the element of linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::display()
{
    node<T> *temp = first;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Singly Linear Linked list and This function is used
//                 to size the element of linked list
// Parameter     :
// Return Value  : int
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::insertfirst(T val)
{
    node<T> *newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE))
                                 // Allocate the memory

    newn->data = val;  // Initialise the data
    newn->next = NULL; // Initialise the Pointer

    if (first == NULL) // Linked list is empty
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::insertlast(T no)
{
    node<T> *newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE))
                                 // Allocate the memory

    newn->data = no;   // Initialise the data
    newn->next = NULL; // Initialise the Pointer

    if (first == NULL)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::insertatpos(T val, int ipos)
{

    node<T> *newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE))

    newn->data = val;
    newn->next = NULL;
    if (ipos < 1 || ipos > isize + 1)
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
        node<T> *temp = first;

        for (int i = 1; i < ipos - 1; i++)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deletefirst()
{
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deletelast()
{
    node<T> *temp = first;

    if (first == NULL)
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
// Description   : It is Singly Liear Linked list and This function is
//                 used to Delete the node  at perticular position of Linked list
// Parameter     : Position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyllist<T>::deleteatpos(int ipos)
{

    if (ipos < 1 || ipos > isize)
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

public:
    singlyclist();
    int size();
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
    first = NULL;
    last = NULL;
    isize = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Singly Circular  Linked list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::display()
{
    node<T> *temp = first;

    if ((first == NULL) && (last == NULL))
    {
        return;
    }

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
// Return Value  : int
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::insertfirst(T val)
{
    node<T> *newn = new struct node<T>;

    newn->data = val;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void singlyclist<T>::insertlast(T val)
{
    node<T> *newn = new struct node<T>;

    newn->data = val;
    newn->next = NULL;

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
// Function Name : insertatpos
// Description   : It is Singly Circular Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::insertatpos(T val, int ipos)
{
    if ((ipos < 1) || (ipos > (isize + 1)))
    {
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
        node<T> *newn = new struct node<T>;

        newn->data = val;
        newn->next = NULL;

        node<T> *temp = first;

        for (int i = 1; i < ipos - 1; i++)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void singlyclist<T>::deletefirst()
{
    if ((first == NULL) && (last == NULL))
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
        first = first->next;
        delete last->next;
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::deletelast()
{
    node<T> *temp = first;

    if ((first == NULL) && (last == NULL))
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

////////////////////////////////////////////////////////////////////
//
// Function Name : deleteatpos
// Description   : It is Singly Circular Linked list and This function is
//                 used to Delete the node at perticular position of Linked list
// Parameter     : Position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void singlyclist<T>::deleteatpos(int ipos)
{
    if ((ipos < 1) || (ipos > isize))
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
        node<T> *temp = first;
        for (int i = 1; i < ipos - 1; i++)
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

public:
    doublyllist();
    int size();
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
    first = NULL;
    isize = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Doubly Linear Linked list and This function is used
//                 to size the elements of linked list
// Parameter     :
// Return Value  : int
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
// Function Name : display
// Description   : It is Doubly Linear Linked list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::display()
{
    node1<T> *temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : insertfirst
// Description   : It is Doubly Linear Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::insertfirst(T val)
{
    node1<T> *newn = new node1<T>;
    newn->data = val;
    newn->next = NULL;
    newn->prev = NULL;

    if (isize == 0)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::insertlast(T val)
{
    node1<T> *newn = new node1<T>;
    newn->data = val;
    newn->next = NULL;
    newn->prev = NULL;
    if (isize == 0)
    {
        first = newn;
    }
    else if (first->next == NULL)
    {
        first->next = newn;
        first->next->prev = first;
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::insertatpos(T val, int ipos)
{
    if (ipos < 1 && ipos > isize + 1)
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

        node1<T> *newn = new node1<T>;
        newn->data = val;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < ipos - 1; i++)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::deletefirst()
{
    node1<T> *temp = first;

    if (isize == 0)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyllist<T>::deletelast()
{
    node1<T> *temp = first;

    if (isize == 0)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyllist<T>::deleteatpos(int ipos)
{
    if (ipos < 1 && ipos > isize)
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

        for (int i = 1; i < ipos - 1; i++)
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
//     DOUBLY CIRCULAR LINKED LIST    //                                        //
////////////////////////////////////////

template <class T>
class doublyclist
{
private:
    node1<T> *first;
    node1<T> *last;
    int isize;

public:
    doublyclist();
    int size();
    void display();
    void insertfirst(T val);
    void insertlast(T val);
    void insertatpos(T val, int ipos);
    void deletefirst();
    void deletelast();
    void deleteatpos(int ipos);
};

template <class T>
doublyclist<T>::doublyclist()
{
    first = NULL;
    last = NULL;
    isize = 0;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Doubly Circular Linked list and This function is used
//                 to size the element  of linked list
// Parameter     :
// Return Value  : int
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
// Description   : It is Doubly Circular Linked list and This function is used
//                 to display the element  of linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyclist<T>::display()
{
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
// Function Name : insertfirst
// Description   : It is Doubly Circular Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::insertfirst(T val)
{
    node1<T> *newn = new node1<T>;

    newn->data = val;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
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
// Function Name : insertlast
// Description   : It is Doubly Circular Linked list and This function is
//                 used to insert the node at last position of Linked list
// Parameter     : Data of node
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void doublyclist<T>::insertlast(T val)
{
    node1<T> *newn = new node1<T>;

    newn->data = val;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
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
// Function Name : insertatpos
// Description   : It is Doubly Circular Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::insertatpos(T val, int ipos)
{
    if ((ipos < 1) || (ipos > isize + 1))
    {
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
        node1<T> *newn = new node1<T>;

        newn->data = val;
        newn->next = NULL;
        newn->prev = NULL;

        node1<T> *temp = first;

        for (int i = 1; i < ipos - 1; i++)
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
// Description   : It is Doubly Circular Linked list and This function is
//                 used to Delete the node at first position of Linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::deletefirst()
{
    if ((first == NULL) && (last == NULL))
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
        first = first->next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deletelast
// Description   : It is Doubly Circular Linked list and This function is
//                 used to Delete the node at last position of Linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::deletelast()
{
    if ((first == NULL) && (last == NULL))
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
        last = last->prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    isize--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : deleteatpos
// Description   : It is Doubly Circular Linked list and This function is
//                 used to Delete at perticular position of Linked list
// Parameter     : Position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void doublyclist<T>::deleteatpos(int ipos)
{
    if ((ipos < 1) || (ipos > isize))
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

public:
    stack();
    void display();
    int size();
    void push(T);
    void pop();
};
template <class T>
stack<T>::stack()
{
    first = NULL;
    last = NULL;
    isize = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is stack Data Structure and This function is used
//                 to display the element  of stack
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::display()
{
    stacknode<T> *temp = first;

    if ((first == NULL) && (last == NULL))
    {
        return;
    }

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
// Description   : It is stack Data Structure and This function is used
//                 to size the element  of linked list
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
    stacknode<T> *newn = new struct stacknode<T>;

    newn->data = Val;
    newn->next = NULL;

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

    if ((first == NULL) && (last == NULL))
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
    Queuenode<T> *front;
    Queuenode<T> *rare;
    int isize;

public:
    queue();
    void display();
    int size();
    void push(T);
    void pop();
};

template <class T>
queue<T>::queue()
{
    front = NULL;
    rare = NULL;
    isize = 0;
}
////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is Queue Data Structure and This function is used
//                 to display the element  of queue
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::display()
{
    Queuenode<T> *temp = front;

    if ((front == NULL) && (rare == NULL))
    {
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

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is Queue Data Structure and This function is used
//                 to size the element  of queue
// Parameter     :
// Return Value  : int
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::push(T val) // insertlast
{
    Queuenode<T> *newn = new struct Queuenode<T>;

    newn->data = val;
    newn->next = NULL;

    if ((front == NULL) && (rare == NULL))
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void queue<T>::pop() // deletefirst
{
    if ((front == NULL) && (rare == NULL))
    {
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

public:
    deque();
    int size();
    void push_front(T);
    void push_back(T);
    void pop_front();
    void pop_back();
    int Front();
    int back();
};

template <class T>
deque<T>::deque()
{
    front = NULL;
    rare = NULL;
    isize = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to return the size of queue
// Parameter     :
// Return Value  : int
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
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_front(T val)
{
    dequenode<T> *newn = new struct dequenode<T>;

    newn->data = val;
    newn->next = NULL;

    if ((front == NULL) && (rare == NULL))
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::push_back(T no)
{
    dequenode<T> *newn = new struct dequenode<T>;

    newn->data = no;
    newn->next = NULL;

    if ((front == NULL) && (rare == NULL))
    {
        
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_front()
{
    if ((front == NULL) && (rare == NULL))
    {
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void deque<T>::pop_back()
{
    dequenode<T> *temp = front;

    if ((front == NULL) && (rare == NULL))
    {
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
        while (temp->next != rare)
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
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
int deque<T>::Front()
{
    return front->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is deque(Double ended queue) Data Structure and This function is
//                 used to get the element of back of queue
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
int deque<T>::back()
{
    return rare->data;
}

///////////////////////////////////
//     VECTOR DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class vector
{
private:
    int *Arr;
    int iCapacity;
    int iCurrent;

public:
    vector();
    ~vector();
    void push_back(T data);
    void push_back(T data, int index);
    void pop_back();
    int at(int index);
    int size();
    void set(int index, T data);
    int capacity();
    void print();
    int operator[](int i);
};
// Default constructor to initialise
// an initial capacity of 1 element and
// allocating storage using dynamic allocation
template <class T>
vector<T>::vector()
{
    Arr = new int[1];
    iCapacity = 1;
    iCurrent = 0;
}
// destructor to deallocate storage allocated by dynamic allocation
// to prevent memory leak
template <class T>
vector<T>::~vector()
{
    delete[] Arr;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is vector Data Structure and This function is
//                 used to push the element at the last index of vector
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data)
{
    // if the number of elements is equal to the
    // capacity, that means we don't have space to
    // accommodate more elements. We need to double the
    // capacity
    if (iCurrent == iCapacity)
    {
        int *temp = new int[2 * iCapacity];
        // copying old array elements to new array
        for (int i = 0; i < iCapacity; i++)
        {
            temp[i] = Arr[i];
        }
        // deleting previous array
        delete[] Arr;

        iCapacity = iCapacity * 2;
        Arr = temp;
    }
    // Inserting data
    Arr[iCurrent] = data;
    iCurrent++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is vector Data Structure and This function is
//                 used to push the element at the last index of vector
// Parameter     : data and index
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data, int index)
{
    // if index is equal to capacity then this
    // function is same as push defined above
    if (index == iCapacity)
    {
        push_back(data);
    }
    else
    {
        Arr[index] = data;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is vector Data Structure and This function is
//                 used to pop(delete) the element at the last index of vector
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::pop_back()
{
    iCurrent--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : at
// Description   : It is vector Data Structure and This function is
//                 used to return the element at given index
// Parameter     : index
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::at(int index)
{
    // if index is within the range
    if (index < iCurrent)
    {
        return Arr[index];
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is vector Data Structure and This function is
//                 used to return the size of vector
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::size()
{
    return iCurrent;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : capacity
// Description   : It is vector Data Structure and This function is
//                 used to return the current capacity of vector
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::capacity()
{
    return iCapacity;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : print
// Description   : It is vector Data Structure and This function is
//                 used to print the data store in vector
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::print()
{
    for (int i = 0; i < iCurrent; i++)
    {
        printf("%d ", Arr[i]);
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : operator
// Description   : It is vector Data Structure and This function is
//                 used to return the element at gievn index and
//                 this function also overload the [] bracket.
// Parameter     : data
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::operator[](int i)
{
    return Arr[i];
}

////////////////////////////////////////////////////////////////////
//
// Function Name : set
// Description   : It is vector Data Structure and This function is
//                 used to set or update the data on given index
//                 the data
// Parameter     : index and data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::set(int index, T data)
{
    Arr[index] = data;
}
int main()
{

    return 0;
}