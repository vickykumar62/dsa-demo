#include<bits/stdc++.h>
using namespace std;

void heapify(int parent, int arr[], int n) {
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (parent != largest) {
        swap(arr[parent], arr[largest]);
        heapify(largest, arr, n);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(i, arr, n);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr[] = {2,5,3,9,4,8,1,6};
    int n = 8;

    buildMaxHeap(arr, n);

    print(arr, n);

    return 0;
}

// 1. Leaves are already heaps.
// 2. Last non-leaf = n/2 - 1.
// 3. Loop from n/2 - 1 to 0.
// 4. Heapify each node.

// We are given: Unsorted array , Convert it into Max Heap 
// Max Heap Rule: Parent >= Children

// Leaf nodes are already valid heaps.
// Why?
// Because:
// They have no children → heap property automatically satisfied.
// So we DO NOT need to heapify leaves.

// For array of size n: Last non-leaf node = n/2 - 1

// Start from last non-leaf node
// Move backward
// Heapify each node

// Fix from middle to root
// Total = O(n)

