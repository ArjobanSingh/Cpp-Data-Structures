#include <iostream>

using namespace std; 

const int INITIAL_CAPACITY = 1;
template <class T>
class MaxPQ
{
    private:
        T *items;
        int sizeOfPQ;
        int sizeOfItemsArr;
        void swap(int i, int j);
        void swim(int index);
        void sink(int index);
        void resize(char action);
    public:
        MaxPQ(); 
        MaxPQ(T* itemsArr, int size);
        void insert(T element);
        T deleteMax();
        T max();
        void print();
        bool isEmpty();
        int size();
};

template <class T>
void MaxPQ<T>::print() {
    if (sizeOfPQ == 0) cout << "empty";
    for (int i = 1; i <= sizeOfPQ; i++) {
        cout << items[i] << " ";
    }
}

template <class T>
MaxPQ<T>::MaxPQ() 
{
    items = new T[INITIAL_CAPACITY];
    sizeOfPQ = 0;
    sizeOfItemsArr = 1;
}

template <class T>
MaxPQ<T>::MaxPQ(T* itemsArr, int size)
{

    items = new T[size + 1];
    // leaving first element to be empty
    for (int i = 0; i < size; i++) {
        items[i + 1] = itemsArr[i];
    }
    sizeOfPQ = size;
    sizeOfItemsArr = size + 1;

    // reach the last branch of tree, and start checking it and converting it to Max priority queue
    for (int i = sizeOfPQ/2; i >= 1; i--) {
        sink(i);
    }
}

template <class T>
void MaxPQ<T>::swap(int i, int j) {
    T temp = items[i];
    items[i] = items[j];
    items[j] = temp;
}


template <class T>
void MaxPQ<T>::sink(int index) {
    while (2*index <= sizeOfPQ) {
        int biggestChild = 2 * index;
        // check which is bigest child
        if (biggestChild < sizeOfPQ && items[biggestChild] < items[biggestChild + 1]) biggestChild++;

        // check if parent is not less than biggest Child than break
        if (items[index] >= items[biggestChild]) break;

        // if biggest child is biogger than parent, than swap
        swap(index, biggestChild);

        index = biggestChild;
    }
}

template <class T>
void MaxPQ<T>::swim(int index) {

    // while we didn't reach root, check if child is bigger than its parent
    // swap them and change index of child to of its previous parent
    while (index > 1 && items[index] > items[index/2]) {
        swap(index, index/2);
        index = index/2;
    }
}


template <class T>
void MaxPQ<T>::resize(char action) {
    if (action == 'D') {
        int capacity = sizeOfItemsArr * 2;
        T *temp = new T[capacity];
        for (int i = 1; i < capacity; i++ ) {
            temp[i] = items[i];
        } 
        items = temp;
        sizeOfItemsArr = capacity;
    } else {
        int capacity = sizeOfItemsArr * 0.50;
        T *temp = new T[capacity];
        for (int i = 1; i <= sizeOfPQ; i++) {
            temp[i] = items[i];
        }
        items = temp;
        sizeOfItemsArr = capacity;
    }

}

template <class T>
void MaxPQ<T>::insert(T element) {
    if (sizeOfPQ == sizeOfItemsArr - 1) resize('D');

    items[++sizeOfPQ] = element;
    swim(sizeOfPQ);
}

template <class T>
T MaxPQ<T>::deleteMax() {
    if (isEmpty() == true) throw std::invalid_argument( "No elemets in Max Priority queue" );
    if (sizeOfPQ == sizeOfItemsArr/4) resize('H');

    T max = items[1];
    swap(1, sizeOfPQ--);
    sink(1);
    // items[sizeOfPQ + 1] = NULL;
    return max;
}

template <class T>
T MaxPQ<T>::max() {
    if (isEmpty() == true) throw std::invalid_argument( "No elemets in Max Priority queue" );
    return items[1];
}

template <class T>
bool MaxPQ<T>::isEmpty() {
    if (sizeOfPQ == 0) return true;
    return false;
}

template <class T>
int MaxPQ<T>::size() {
    return sizeOfPQ;
}
