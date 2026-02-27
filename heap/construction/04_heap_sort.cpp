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

void sortArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);     // move max to end
        heapify(0, arr, i);       // fix reduced heap
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
    print(arr,n);

    sortArray(arr, n);
    print(arr, n);

    return 0;
}

// Step 1: Build Max Heap
// Largest element comes to root.

// Step 2: Swap root with last element
// Now largest element is at correct sorted position.

// Step 3: Reduce heap size
// Ignore last sorted element.

// Step 4: Heapify root again
// Bring next largest to root.

// Repeat until size = 1.

// time complexcity is nlog(n)
// space complexcity is o(1) , when heapify is written in iterative manner 