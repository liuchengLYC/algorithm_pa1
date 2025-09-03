// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
//  Modify     [2024/9/2 Meng-Chen Wu]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data) {
    int len = data.size();
    for (int i = 1; i < len; i++) {
        int val = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > val) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = val;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int> &data, int f) {
    QuickSortSubVector(data, 0, data.size() - 1, f);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int> &data, int low, int high,
                                  const int flag) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    // flag == 0 -> normal QS
    // flag == 1 -> randomized QS
}
int SortTool::RandomizedPartition(vector<int> &data, int low, int high) {
    // Function : RQS's Partition the vector
    // TODO : Please complete the function
}
int SortTool::Partition(vector<int> &data, int low, int high) {
    // Function : Partition the vector
    // TODO : Please complete the function
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data) {
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    SortTool::MergeSortSubVector(data, low, mid);
    SortTool::MergeSortSubVector(data, mid + 1, high);
    SortTool::Merge(data, low, mid, mid + 1, high);
}

// Merge
void SortTool::Merge(vector<int> &data, int low, int middle1, int middle2,
                     int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    
}

// bottom-up style implementation of merge sort
void SortTool::BottomUpMergeSort(vector<int> &data) {
    /*TODO :
      Implement merge sort in bottom-up style, in other words,
      without recursive function calls.
      Hint:
      1. Divide data to n groups of one data each group
      2. Iteratively merge each pair of 2 neighbor groups into one larger group
      3. Finally we obtain exactly one sorted group
    */
}

// Heap sort method, be aware that you are NOT required to implement heap sort
// in PA1
void SortTool::HeapSort(vector<int> &data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will
    // be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0);
    }
}

// Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left
    // sub-tree are max-heap
}

// Build max heap
void SortTool::BuildMaxHeap(vector<int> &data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
}
