#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;   // number of elements present

public:
    // Constructor
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
    }

    // Enqueue
    void push(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }

        arr[rearIndex] = value;

        // move rear circularly
        rearIndex = (rearIndex + 1) % capacity;

        count++;
    }

    // Dequeue
    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }

        // move front circularly
        frontIndex = (frontIndex + 1) % capacity;

        count--;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return arr[frontIndex];
    }

    // Current size
    int size() {
        return count;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.pop();
    q.pop();

    q.push(60);
    q.push(70);

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
