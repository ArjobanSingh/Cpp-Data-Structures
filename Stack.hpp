#include <iostream>

using namespace std;

const int INITIALSIZE = 1;

template <class T>
class Stack
{
    private:
    int size, arrSize;
    T *stackArr; // = new T[INITIALSIZE];
    void resizeArr(char action);

    public:
    Stack(T randomVal);
    void push(T val);
    T pop();
    int isEmpty();
    void printStack();
    int returnStackSize();
    T peek();
};

template <class T>
Stack<T>::Stack(T randomVal)
{
    arrSize = INITIALSIZE;
    stackArr = new T[arrSize];
    size = -1;
    for (int i = 0; i < arrSize; i++ )
    {
        stackArr[i] = randomVal;
    }
}

template <class T>
void Stack<T>::printStack()
{
    if (isEmpty()) cout << "Stack is empty ";
    // printing from last element as stack is LIFO
    for (int i = size; i > -1; i--)
    {
        cout << stackArr[i] << "\n";
    }
}

template <class T>
int Stack<T>::isEmpty()
{
    if (size == -1 ) return 1;
    return 0;
}

template <class T>
int Stack<T>::returnStackSize()
{
    return size + 1;
}

template <class T>
T Stack<T>::peek()
{
    if (this->isEmpty()) return -1;
    return stackArr[size];
}

template <class T>
void Stack<T>::push(T val)
{
    // array is full need to resize array
    if (arrSize - 1 == size)
    {
        resizeArr('D');
        stackArr[++size] = val;
    }
    else
    {
        stackArr[++size] = val;
    }
}

template <class T>
T Stack<T>::pop()
{
    if (this->isEmpty()) return -1;

    // array is 1/4 full only, need to decrease the size to half of it
    if (arrSize * 0.25 == size)
    {
        resizeArr('H');
        T val = stackArr[size--];
        return val;
    }
    else
    {
        T val = stackArr[size--];
        return val;
    }
}

template <class T>
void Stack<T>::resizeArr(char action)
{
    // D means double the array
    if (action == 'D')
    {
        // this will not work here:- T newArr[2 * arrSize];
        // this will work but older way: T *newArr = (T*) malloc(sizeof(T) * (2 * arrSize));

        // new way to allocate dynamic memory using new keyword.
        T *newArr = new T[2 * arrSize];
        for (int i = 0; i < arrSize; i++)
        {
            newArr[i] = stackArr[i];
        } 
        arrSize = 2 * arrSize;
        // stackArr = NULL;
        stackArr = newArr;
    }
    // H means half the array
    else if (action == 'H')
    {
        int newSize = 0.5 * arrSize;
        T *newArr = new T[newSize];
        for (int i = 0; i < newSize; i++)
        {
            newArr[i] = stackArr[i];
        }
        arrSize = newSize;
        stackArr = newArr;
    }

}