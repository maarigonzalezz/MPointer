//
// Created by gonza on 11/09/2024.
//

#ifndef SORTERS_H
#define SORTERS_H



#include <vector>

class Sorters {
public:
    // QuickSort
    void quickSort(std::vector<int>& arr, int low, int high);

    // BubbleSort
    void bubbleSort(std::vector<int>& arr);

    // InsertionSort
    void insertionSort(std::vector<int>& arr);

private:
    int partition(std::vector<int>& arr, int low, int high);
};



#endif //SORTERS_H
