#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int* arr;
    int size;
    int total_size;

public:
    // Constructor
    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert element
    void insert(int x) {
        if (size == total_size) {
            cout << "Heap is full, cannot insert\n";
            return;
        }

        arr[size] = x;
        int index = size;
        size++;

        // Move upward (Heapify Up)
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }

    // Heapify Down
    void heapify(int parent) {
        int largest = parent;
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != parent) {
            swap(arr[parent], arr[largest]);
            heapify(largest);
        }
    }

    // Delete root
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        swap(arr[0], arr[size - 1]);
        size--;

        heapify(0);
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Destructor
    ~MaxHeap() {
        delete[] arr;
    }
};

int main() {

    MaxHeap h1(20);

    h1.insert(10);
    h1.insert(40);
    h1.insert(20);
    h1.insert(50);

    h1.print();

    h1.deleteRoot();
    h1.print();

    return 0;
}

// Rule 1:
// Heap is Complete Binary Tree.

// Rule 2:
// Array Index Formula:
// Left  = 2*i + 1
// Right = 2*i + 2
// Parent = (i - 1)/2

// Rule 3:
// Insert = Add at end + Heapify Up.

// Rule 4:
// Delete Root = Swap with last + Heapify Down.

// Rule 5:
// Heap height = log n.

// Time Complexity
// Insert = O(log n)

// If we insert n elements: n x log n = O(n log n)

// Building heap using insert = O(n log n)



