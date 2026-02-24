class MyQueue {
public:

    /*
    input stack  → used for push operation
    output stack → used for pop/peek operation
    */
    stack<int> input;
    stack<int> output;

    MyQueue() {
        // Nothing to initialize
    }
    
    /*
    Push operation:
    Simply push into input stack.
    O(1)
    */
    void push(int x) {
        input.push(x);
    }
    
    /*
    Pop operation:
    If output stack is not empty → pop from output.

    If output is empty:
    Transfer all elements from input to output.
    This reverses order and makes oldest element
    appear on top of output stack.
    */
    int pop() {

        if(output.empty()){

            // Move elements only when needed
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();
        output.pop();
        return val;
    }
    
    /*
    Peek operation:
    Same logic as pop,
    but do not remove element.
    */
    int peek() {

        if(output.empty()){

            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }
    
    /*
    Queue is empty only if both stacks are empty.
    */
    bool empty() {
        return input.empty() && output.empty();
    }
};