#include <iostream>

template <class T>
class HeapSort
{
    private:
        T *arr;
        int arrSize;
        void swap(int i, int j);
        void sink(int index);
    public:
        HeapSort(T* arr, int size);
        void sort();    
};

template <class T>
HeapSort<T>::HeapSort(T* arr, int size) {
    this->arr = arr;
    arrSize = size;
}

template <class T>
void HeapSort<T>::sort() {
    for (int i = arrSize/2; i >= 1; i--) {
        sink(i);
    }

    while (arrSize > 1) {
        swap(1, arrSize--);
        sink(1);
    }
}


template <class T>
void HeapSort<T>::sink(int index) {
    while (2 * index <= arrSize) {
        int biggestChild = 2 * index;
        if (biggestChild < arrSize && arr[biggestChild] < arr[biggestChild + 1]) ++biggestChild;
        if (arr[index] >= arr[biggestChild]) break;

        swap(index, biggestChild);
        index = biggestChild; 
    }
}

template <class T>
void HeapSort<T>::swap(int i, int j) {
    T temp = arr[i - 1];
    arr[i - 1] = arr[j - 1];
    arr[j - 1] = temp;
}