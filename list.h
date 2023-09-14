#include <iostream>
using namespace std;
template <class T>
class node1 // class declaration of doubly linked list
{
public:
    T data;
    class node1 *next;
    class node1 *prev;
    node1(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
////////////////////////////////////////
//     DOUBLY CIRCULAR LINKED LIST    //                                        //
////////////////////////////////////////

template <class T>
class list
{
private:
    node1<T> *first;
    node1<T> *last;
    int isize;

public:
    list();
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
int list<T>::size()
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
void list<T>::display()
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
// Function Name : push_front
// Description   : It is Doubly Circular Linked list and This function is
//                 used to insert at first position of Linked list
// Parameter     : Data of node
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::push_front(T val)
{
    node1<T> *newn = new node1<T>(val);
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
// Function Name : push_back
// Description   : It is Doubly Circular Linked list and This function is
//                 used to insert the node at last position of Linked list
// Parameter     : Data of node
// Return Value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void list<T>::push_back(T val)
{
    node1<T> *newn = new node1<T>(val);

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
// Function Name : insert
// Description   : It is Doubly Circular Linked list and This function is
//                 used to insert at perticular position of Linked list
// Parameter     : Data of node and position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::insert(T val, int ipos)
{
    if ((ipos < 1) || (ipos > isize + 1))
    {
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
// Function Name : pop_front
// Description   : It is Doubly Circular Linked list and This function is
//                 used to Delete the node at first position of Linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::pop_front()
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
// Function Name : pop_back
// Description   : It is Doubly Circular Linked list and This function is
//                 used to Delete the node at last position of Linked list
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::pop_back()
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
// Function Name : deletenode
// Description   : It is Doubly Circular Linked list and This function is
//                 used to Delete at perticular position of Linked list
// Parameter     : Position
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void list<T>::deletenode(int ipos)
{
    if ((ipos < 1) || (ipos > isize))
    {
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
// Description   : It is Doubly Circular Linked list and This function is
//                 returns the value of the first element in the list.
// Parameter     :
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T list<T>::front()
{
    return first->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : back
// Description   : It is Doubly Circular Linked list and This function is
//                 returns the value of the last element in the list.
// Parameter     :
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
T list<T>::back()
{
    return first->data;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : begin
// Description   : It is Doubly Circular Linked list and This function is
//                 returns an iterator pointing to the first element of the list.
// Parameter     :
// Return Value  : any data
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
// Description   : It is Doubly Circular Linked list and This function is
//                 returns an iterator pointing to the theoretical last element which follows the last element.
// Parameter     :
// Return Value  : any data
//
////////////////////////////////////////////////////////////////////

template <class T>
node1<T> *list<T>::end()
{
    return last;
}
