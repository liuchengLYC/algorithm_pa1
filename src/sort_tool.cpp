// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
//  Modify     [2024/9/2 Meng-Chen Wu]
// **************************************************************************

#include "sort_tool.h"
#include <climits>
#include <iostream>
#include <utility>
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
    if (low >= high)
        return;
    int pivot = ((flag == 0) ? Partition(data, low, high)
                             : RandomizedPartition(data, low, high));
    QuickSortSubVector(data, low, pivot - 1, flag);
    QuickSortSubVector(data, pivot + 1, high, flag);
}
int SortTool::RandomizedPartition(vector<int> &data, int low, int high) {
    int i = rand() % (high - low + 1) + low;
    swap(data[i], data[high]);
    return Partition(data, low, high);
}
int SortTool::Partition(vector<int> &data, int low, int high) {
    int lbound = low;
    int pivot = data[high];
    for (int i = low; i < high; i++) {
        if (data[i] <= pivot) {
            swap(data[i], data[lbound]);
            lbound++;
        }
    }
    swap(data[lbound], data[high]);
    return lbound;
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data) {
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high) {
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
    if (high == low + 1) {
        if (data[high] < data[low]) {
            swap(data[low], data[high]);
        }
        return;
    }
    // vector<int> sub1;
    // vector<int> sub2;
    // for (int i = low; i < middle1 + 1; i++)
    //     sub1.push_back(data[i]);
    // for (int i = middle2; i < high + 1; i++)
    //     sub2.push_back(data[i]);
    vector<int> sub1(data.begin() + low, data.begin() + middle1 + 1);
    vector<int> sub2(data.begin() + middle2, data.begin() + high + 1);
    
    // Below method fail as long as INT_MAX exists in testcase
    // sub1.push_back(INT_MAX);
    // sub2.push_back(INT_MAX);
    // int i = 0, j = 0, pos = low;
    // while (true) {
    //     int v1 = sub1[i], v2 = sub2[j];
    //     if (v1 == INT_MAX && v2 == INT_MAX)
    //         break;
    //     else if (v1 < v2) {
    //         data[pos++] = v1;
    //         i++;
    //     } else {
    //         data[pos++] = v2;
    //         j++;
    //     }
    // }
    int i = 0, j = 0, pos = low;
    while (i < sub1.size() && j < sub2.size()) {
        if (sub1[i] <= sub2[j])
            data[pos++] = sub1[i++];
        else
            data[pos++] = sub2[j++];
    }
    while (i < sub1.size())
        data[pos++] = sub1[i++];
    while (j < sub2.size())
        data[pos++] = sub2[j++];
}

// bottom-up style implementation of merge sort
void SortTool::BottomUpMergeSort(vector<int> &data) {
    int len = data.size(), size = 1;
    while (size < len) {
        int low = 0;
        while (low < len - size) {
            int mid = low + size - 1;
            int high = min(low + 2 * size - 1, len - 1);
            SortTool::Merge(data, low, mid, mid + 1, high);
            low += 2 * size;
        }
        size *= 2;
    }
}

// Heap sort method, be aware that you are NOT required to implement heap sort
// in PA1
void SortTool::HeapSort(vector<int> &data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0);
    }
}

// Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root) {
    int left = 2 * root + 1, right = 2 * root + 2, largest = root;
    if (left < heapSize && data[left] > data[largest])
        largest = left;
    if (right < heapSize && data[right] > data[largest])
        largest = right;
    if (largest != root) {
        swap(data[largest], data[root]);
        MaxHeapify(data, largest);
    }
}

// Build max heap
void SortTool::BuildMaxHeap(vector<int> &data) {
    heapSize = data.size(); // initialize heap size
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        MaxHeapify(data, i);
    }
}
