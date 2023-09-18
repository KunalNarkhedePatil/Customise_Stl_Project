#include <iostream>
using namespace std;
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
    int iSize;

public:
    stack();
    stack(int iSize);
    bool empty();
    T top();
    void display();
    int size();
    void push(T val);
    void pop();
};
template <class T>
stack<T>::stack(int iSize)
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->iSize = iSize;
}
template <class T>
stack<T>::stack()
{
    this->first = NULL;
    this->last = NULL;
    this->isize = 0;
    this->iSize = -1;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is stack Data Structure and This function is used
//                 to check stack is empty or not
// Parameter     :
// Return value  : void
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
// Return value  : void
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
        cout << "|" << temp->data << "|-> ";
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
// Return value  : any datatype
//
////////////////////////////////////////////////////////////////////

template <class T>
T stack<T>::top()
{
    if (empty())
    {
        cout << "stack is empty" << endl;
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
// Function Name : push
// Description   : It is stack Data Structure and This function is
//                 used to push(insert) the element into stack
// Parameter     : data
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::push(T val)
{
    stacknode<T> *newn = new stacknode<T>(val);

    if (isize == iSize)
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
// Return value  : void
//
////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::pop()
{
    stacknode<T> *temp = first;

    if (empty())
    {
        cout << "stack is empty" << endl;
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
