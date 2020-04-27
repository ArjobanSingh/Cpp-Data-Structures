#include "MergeSort.hpp"
#include "InsertionSort.hpp"

int main(){
    cout << "Starting method\n";
    int testArr[] = { 156, 234, 1, 10, 8, 4, 2, 99, 28, 689, 23, 5, 3};
    cout << "Before sorting\n";
    int arr_size = sizeof(testArr)/sizeof(testArr[0]); 
    for (int i = 0; i < arr_size; i++)
    {
        cout << testArr[i] << " ";
    }
    mergeSort(testArr, arr_size);

    cout << "\nIt should sort now with MergeSort\n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << testArr[i] << " ";
    }

    int secondArr[] = {156, 234, 1, 10, 8, 4, 2, 99, 28, 689, 23, 5, 3};
    arr_size = sizeof(secondArr)/sizeof(secondArr[0]); 
    insertionSort(secondArr, arr_size);
    cout << "\nIt should sort now with InsertionSort\n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << testArr[i] << " ";
    }
    return 0;
}