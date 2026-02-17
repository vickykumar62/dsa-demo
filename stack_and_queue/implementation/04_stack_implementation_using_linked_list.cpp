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

class Stack {
    ListNode* topNode;   // pointer to top of stack
    int count;           // size of stack

public:
    // Constructor
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    // Push element (insert at head)
    void push(int value) {

        // Create new node
        ListNode* newNode = new ListNode(value);

        // New node points to current top
        newNode->next = topNode;

        // Move top to new node
        topNode = newNode;

        count++;
    }

    // Pop element (remove from head)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        ListNode* temp = topNode;

        // Move top to next node
        topNode = topNode->next;

        delete temp;   // free memory
        count--;
    }

    // Return top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        return topNode->val;
    }

    // Check if empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Return size
    int size() {
        return count;
    }

    // Destructor to free remaining nodes
    ~Stack() {
        while (topNode != nullptr) {
            ListNode* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;
    cout << "Size after pop: " << st.size() << endl;

    return 0;
}
