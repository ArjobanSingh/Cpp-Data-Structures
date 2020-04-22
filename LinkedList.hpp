#include <iostream>
using namespace std;

// Doubley Linked List

template <class T> 
class LinkedList
{

    private:
        class Node
        {
            public:
            T data;
            Node *next;
            Node *previous;
        };
        Node *head;
        Node *tail;
        int size;

    public:
        LinkedList();
        void addFirst(T element);
        void addLast(T element);
        T deleteFirst();
        T deleteLast();
        T getFirst();
        T getLast();
        T getElementAtPosition(int n);
        void updateElementAtPosition(T element, int position);
        void addNewElementAtPosition(T element, int position);
        int returnSize();
        void printList();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
T LinkedList<T>::getFirst()
{
    if (head != nullptr)
    {
        return head->data;
    }
   throw std::invalid_argument( "List is empty" );
}

template <class T>
T LinkedList<T>::getLast()
{
    if (tail != nullptr)
    {
        return tail->data;
    }
   throw std::invalid_argument( "List is empty" );
}

template <class T>
T LinkedList<T>::getElementAtPosition(int n)
{
    if (n < this->returnSize() && n >= 0)
    {
        Node *temp = head;
        for (int i = 0; i < n; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    throw std::invalid_argument( "Index out of range" );
}

template <class T>
void LinkedList<T>::updateElementAtPosition(T element, int position)
{
    // position is not out of index
    if (position < this->returnSize() && position >= 0)
    {

        Node *temp = head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->data = element;
        return;
    }
    throw std::invalid_argument( "Index out of bound" );
}


template <class T>
void LinkedList<T>::addNewElementAtPosition(T element, int position)
{

    // position is not out of index
    if (position < this->returnSize() && position >= 0)
    {

        Node *temp = head;

        //itearting till the one position before the position we want to add new element
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }

        // created new node to add element between the temp node and temp's next node,
        // and making temp's next node to bew newNode
        Node *newNode = new Node();
        newNode->data = element;
        newNode->previous = temp;
        newNode->next = temp->next; 
        temp->next = newNode;
        ++size;
        return;
    }
    throw std::invalid_argument( "Index out of bound" );
}

template <class T>
void LinkedList<T>::addFirst(T element)
{
    Node *newNode = new Node();

    // *newNode.data == newNode->data

    newNode->data = element;
    newNode->next = head;
    newNode->previous = nullptr;


    ++size;
    if (size == 1)
    {
        head = newNode;
        tail = head;
    }
    else if (size > 1)
    {
        head->previous = newNode;
        head = newNode;
    }
    
}

template <class T>
void LinkedList<T>::addLast(T element)
{
    Node *newNode = new Node();

    newNode->data = element;
    newNode->next = nullptr;
    newNode->previous = tail;


    ++size;
    if (size == 1)
    {
        tail = newNode;
        head = tail;
    }
    else if (size > 1)
    {
        tail->next = newNode;
        tail = newNode;
    }
    
}

template <class T>
int LinkedList<T>::returnSize()
{
    return size;
}

template <class T>
T LinkedList<T>::deleteFirst()
{
    Node *toDelete = head;
    T returnVal = toDelete->data;
    head = head->next;
    head->previous = nullptr;
    toDelete = nullptr;
    --size;
    return returnVal;
}

template <class T>
T LinkedList<T>::deleteLast()
{
    Node *toDelete = tail;
    T returnVal = toDelete->data;
    tail = tail->previous;
    tail->next = nullptr;
    toDelete = nullptr;
    --size;
    return returnVal;
}

template <class T>
void LinkedList<T>::printList()
{
    Node *first = head;

    while (first != nullptr)
    {
        cout << first->data << " ";
        first = first->next;
    }
}