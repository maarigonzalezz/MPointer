
#include "Sorters.h"

// QuickSort partition function
int Sorters::partition(DoubleLinkedList& arr, int low, int high) {
    int pivot = arr.get(high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr.get(j) < pivot) {
            i++;
            int temp1 = arr.get(i);
            int temp2 = arr.get(j);
            arr.set(i, temp2);
            arr.set(j, temp1);
        }
    }
    // Se intercambia el valor del pivote con el valor en i + 1
    int temp1 = arr.get(i + 1);
    int temp2 = arr.get(high);
    arr.set(i + 1, temp2);
    arr.set(high, temp1);

    return i + 1;
}

// QuickSort algorithm
void Sorters::quickSort(DoubleLinkedList& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// BubbleSort algorithm
void Sorters::bubbleSort(DoubleLinkedList& arr) {
    int n = arr.getLength();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr.get(j) > arr.get(j + 1)) {
                // Intercambiamos los valores en los nodos
                int temp1 = arr.get(j);
                int temp2 = arr.get(j + 1);
                arr.set(j, temp2);
                arr.set(j + 1, temp1);
            }
        }
    }
}

// InsertionSort algorithm
void Sorters::insertionSort(DoubleLinkedList& arr) {
    int n = arr.getLength();
    for (int i = 1; i < n; i++) {
        int key = arr.get(i);
        int j = i - 1;

        // Mueve los elementos de la lista que son mayores que key
        while (j >= 0 && arr.get(j) > key) {
            arr.set(j + 1, arr.get(j));
            j--;
        }
        arr.set(j + 1, key);
    }
}

