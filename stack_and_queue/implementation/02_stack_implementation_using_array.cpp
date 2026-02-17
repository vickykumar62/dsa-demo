#include <iostream>
using namespace std;

class Stack {
    int *arr;      // dynamically allocated array
    int topIndex;  // index of top element
    int capacity;  // maximum size of stack

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;  // stack is empty initially
    }

    // Push element into stack
    void push(int value) {
        // If stack is full
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }

        // Move top forward
        topIndex++;

        // Insert element
        arr[topIndex] = value;
    }

    // Remove top element
    void pop() {
        // If stack is empty
        if (topIndex == -1) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }

        // Just move top backward
        topIndex--;
    }

    // Return top element
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return arr[topIndex];
    }

    // Return current size of stack
    int size() {
        return topIndex + 1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    st.pop();

    cout << "Top element after pop: " << st.top() << endl;
    cout << "Size after pop: " << st.size() << endl;

    return 0;
}
