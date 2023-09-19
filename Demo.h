#include<iostream>
using namespace std;

template <class T>
class stacknode // class declaration of doubly linked list
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
class stack
{
private:
    node1<T> *first;
    node1<T> *last;
    int isize;
    int maxCapacity;

public:
    stack();
    stack(int maxCapacity);
    bool empty();
    int size();
    void display();
    void push(T val);
    void pop();
    
};

template <class T>
stack<T>::stack()
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}
template <class T>
stack<T>::stack(int maxCapacity)
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
bool stack<T>::empty()
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
int stack<T>::size()
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
void stack<T>::display()
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
    cout<<endl;
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
void stack<T>::push(T val)
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
