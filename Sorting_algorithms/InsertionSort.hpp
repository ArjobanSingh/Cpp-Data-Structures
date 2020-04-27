void insertionSort(int *arr, int size);

void insertionSort(int *arr, int size){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > key){
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }
}