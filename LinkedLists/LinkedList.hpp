#include <iostream>
using namespace std;


template <class T>
class LinkedList
{
    private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    int size;

    public:
    LinkedList();
    void addFirst(T element);
    T getFirst();
    T deleteFirst();
    void addNewElementAtPosition(T element, int position);
    void updateElementAtPosition(T element, int position);
    T getElementAtPosition(int position);
    int returnSize();
    void printList();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template <class T>
int LinkedList<T>::returnSize()
{
    return size;
}

template <class T>
void LinkedList<T>::addFirst(T element)
{
    Node *temp = new Node();
    temp->data = element;
    temp->next = nullptr;
    ++size;

    if (size > 1)
    {
        temp->next = head;
    }
    head = temp;
}

template <class T>
T LinkedList<T>::getFirst()
{
    if (this->returnSize() >= 1)
    {
        return head->data;
    }
    throw std::invalid_argument( "List is empty" );
}

template <class T>
T LinkedList<T>::deleteFirst()
{
    if (this->returnSize() >= 1)
    {
        T dataToReturn = head->data;
        head = head->next;
        --size;
        return dataToReturn;
    }
    throw std::invalid_argument( "List is empty" );
}

template <class T>
void LinkedList<T>::addNewElementAtPosition(T element, int position)
{
    // position is not out of index, and is between first and last element, and not even at first and last edges
    // because they have their separate functions
    if (  position > 0 && position < this->returnSize())
    {
        Node *temp = head;

        // loop through, till its gets one element before the required position
        // to add new element between that and its next element
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
    throw std::invalid_argument( "Index out of range or at edges" );
}

template <class T>
void LinkedList<T>::updateElementAtPosition(T element, int position)
{
    // position is not out of range
    if ( position > -1 && position < this->returnSize())
    {
        Node *temp = head;

        // iterating through, till it gets the right element to update 
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->data = element;
        return;
    }
    throw std::invalid_argument( "Index out of range" );
}

template <class T>
T LinkedList<T>::getElementAtPosition(int position)
{
    // position is not out of range
    if ( -1 < position < this->returnSize())
    {
        Node *temp = head;

        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }

        return temp->data;
    }
    throw std::invalid_argument( "Index out of range" );
}
    
template <class T>    
void LinkedList<T>::printList()
{
    Node *temp = head;
    for (int i = 0; i < this->returnSize(); i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Doubly Linked List

template <class T> 
class DoublyLinkedList
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
        DoublyLinkedList();
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
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
T DoublyLinkedList<T>::getFirst()
{
    if (head != nullptr)
    {
        return head->data;
    }
   throw std::invalid_argument( "List is empty" );
}

template <class T>
T DoublyLinkedList<T>::getLast()
{
    if (tail != nullptr)
    {
        return tail->data;
    }
   throw std::invalid_argument( "List is empty" );
}

template <class T>
T DoublyLinkedList<T>::getElementAtPosition(int n)
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
void DoublyLinkedList<T>::updateElementAtPosition(T element, int position)
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
void DoublyLinkedList<T>::addNewElementAtPosition(T element, int position)
{

    // position is not out of index, and is between first and last element, and not even at first and last edges
    // because they have their separate functions
    if (position < this->returnSize() && position > 0)
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
void DoublyLinkedList<T>::addFirst(T element)
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
void DoublyLinkedList<T>::addLast(T element)
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
int DoublyLinkedList<T>::returnSize()
{
    return size;
}

template <class T>
T DoublyLinkedList<T>::deleteFirst()
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
T DoublyLinkedList<T>::deleteLast()
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
void DoublyLinkedList<T>::printList()
{
    Node *first = head;

    while (first != nullptr)
    {
        cout << first->data << " ";
        first = first->next;
    }
}