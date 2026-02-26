#include<bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    int* arr;
    int size;
    int total_size;

public:
    // Constructor
    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert (Heapify Up)
    void insert(int x) {
        if (size == total_size) {
            cout << "Heap is full, cannot insert\n";
            return;
        }

        arr[size] = x;
        int i = size;
        size++;

        // Move upward
        while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }

    // Heapify Down
    void heapify(int parent) {
        int smallest = parent;
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (parent != smallest) {
            swap(arr[parent], arr[smallest]);
            heapify(smallest);
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

    ~MinHeap() {
        delete[] arr;
    }
};

int main() {
    MinHeap h1(20);

    h1.insert(40);
    h1.insert(10);
    h1.insert(30);
    h1.insert(5);

    h1.print();

    h1.deleteRoot();
    h1.print();

    return 0;
}