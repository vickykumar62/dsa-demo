#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Queue {
    ListNode* frontNode;   // points to front element
    ListNode* rearNode;    // points to last element
    int count;

public:
    // Constructor
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    // Push (enqueue) → insert at rear
    void push(int value) {

        ListNode* newNode = new ListNode(value);

        // If queue is empty
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;  // link new node
            rearNode = newNode;        // move rear
        }

        count++;
    }

    // Pop (dequeue) → remove from front
    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }

        ListNode* temp = frontNode;

        frontNode = frontNode->next;   // move front forward

        // If queue becomes empty
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
        count--;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return frontNode->val;
    }

    // Check if empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Return size
    int size() {
        return count;
    }

    // Destructor to free memory
    ~Queue() {
        while (frontNode != nullptr) {
            ListNode* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;
    cout << "Size after pop: " << q.size() << endl;

    return 0;
}
