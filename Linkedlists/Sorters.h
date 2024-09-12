//
// Created by gonza on 11/09/2024.
//

#ifndef SORTERS_H
#define SORTERS_H
#include "DoubleLinkedList.h"
#include <vector>

class Sorters {
public:
    // QuickSort
    void quickSort(DoubleLinkedList& arr, int low, int high);

    // BubbleSort
    void bubbleSort(DoubleLinkedList& arr);

    // InsertionSort
    void insertionSort(DoubleLinkedList& arr);

private:
    int partition(DoubleLinkedList& arr, int low, int high);
};



#endif //SORTERS_H
