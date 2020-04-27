#include <iostream>
using namespace std;

void mergeSort(int *arr, int size);
void sort(int arr[],int left, int right);
void merge(int arr[], int left, int middle, int right);

void mergeSort(int *arr, int size){
    int left = 0;
    int right = size - 1;
    sort(arr, left, right);
}

void sort(int arr[],int left, int right){
    if (left < right){
        int middle = (left + right) /2;

        // sort first and second halves recursively
        sort(arr, left, middle);
        sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right){
    int i, j, k;
    // length of sub array one
    int n = middle - left + 1;
    // length of sub array two
    int m = right - middle;

    int leftArr[n], rightArr[m];

    for (i = 0; i < n; i++){
        leftArr[i] = arr[left + i];
    }
    for (j = 0; j < m; j++){
        rightArr[j] = arr[middle + 1 + j];
    }

    i = 0; j = 0;
    for (int k = left; k <= right; k++){

        // if all elements of left array has stored in array
        if (i >= n){
            arr[k] = rightArr[j++];
        }
        else if(j >= m){
            arr[k] = leftArr[i++];
        }
        else if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i++];
        }
        else{
            arr[k] = rightArr[j++];
        }
    }
}






