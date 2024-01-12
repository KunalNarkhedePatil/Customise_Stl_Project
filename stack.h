#include <iostream>
using namespace std;

template <class T>
class stacknode // class declaration of stack
{
public:
    T data;
    stacknode<T> *next;
    stacknode<T> *prev;
    stacknode(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
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
    ~stack();
    bool empty();
    int size();
    T top();
    void display();
    void push(T val);
    void pop();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : default constructor
// Description   : It is constructor of stack class and This function is automatically
//                 called when object of class is created.this function used to initialise 
//                 the characterstics and allocate the resoures.
// Parameter     :
// Return value  : 
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
stack<T>::stack()
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->maxCapacity = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : parameterized constructor
// Description   : It is constructor of stack class and This function is automatically
//                 called when object of class is created.this function used to initialise 
//                 the characterstics and allocate the resoures.
// Parameter     : integer
// Return value  : 
//
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
stack<T>::stack(int maxCapacity)
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
stack<T>::~stack()
{
    while (!empty())
    {
        pop();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is stack Data Structure and This function is used
//                 to check stack is empty or not
// Parameter     :
// Return Value  : bool
//
///////////////////////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : display
// Description   : It is stack Data Structure and This function is used
//                 to display the element of stack
// Parameter     :
// Return Value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::display()
{
    if (empty())
    {
        cout << "stack is empty" << endl;
        return;
    }
    stacknode<T> *temp = first;

    for (register int i = 1; i <= isize; i++)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : top
// Description   : It is stack Data Structure and This function is used
//                 to return the top element in stack
// Parameter     :
// Return Value  : any datatype
//
///////////////////////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is stack Data Structure and This function is used
//                 to return the size of stack
// Parameter     :
// Return Value  : int
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int stack<T>::size()
{
    return isize;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : push
// Description   : It is stack Data Structure and This function is
//                 used to push(insert) the element into stack
// Parameter     : data
// Return Value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::push(T val)
{
    if (isize == maxCapacity)
    {
        cout << "stack is full\n";
        return;
    }
    stacknode<T> *newn = new stacknode<T>(val);

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

///////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : pop
// Description   : It is stack Data Structure and This function is
//                 used to pop(remove) the element into stack
// Parameter     :
// Return Value  : void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void stack<T>::pop()
{
    if (empty())
    {
        cout << "stack is empty" << endl;
        return;
    }
    else if (isize == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    isize--;
}
