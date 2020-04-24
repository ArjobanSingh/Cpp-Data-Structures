#include <iostream>
# include "../LinkedLists/LinkedList.hpp"

using namespace std;

template <class T>
class Stack_LL
{
    private:
    LinkedList<T> ll;

    public:
    void push(T element);
    T pop();
    T peek();
    int returnStackSize();
    int isEmpty();
    void printStack();
};

template <class T>
int Stack_LL<T>::returnStackSize()
{
    return ll.returnSize();
}

template <class T>
int Stack_LL<T>::isEmpty()
{
    if (this->returnStackSize() > 0) return 0;
    return 1;
}

template <class T>
void Stack_LL<T>::push(T element)
{
    ll.addFirst(element);
}

template <class T>
T Stack_LL<T>::pop()
{
    // means stack is not empty
    if (this->isEmpty() == 0)
    {
        return ll.deleteFirst();
    }
    throw std::invalid_argument( "Stack is already empty" );
}

template <class T>
void Stack_LL<T>::printStack()
{
    if (isEmpty()) cout << "Stack is empty ";
    for (int i = 0; i < ll.returnSize(); i++)
    {
        cout << ll.getElementAtPosition(i) << "\n";
    }
}

template <class T>
T Stack_LL<T>::peek()
{
    // means stack is not empty
    if (this->isEmpty() == 0)
    {
        return ll.getFirst();
    }
    throw std::invalid_argument( "Stack is empty" );
}
