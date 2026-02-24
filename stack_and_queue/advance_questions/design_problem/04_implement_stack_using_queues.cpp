class MyStack {
public:

    /*
    q1 → will always maintain stack order
    q2 → temporary queue used during push
    */
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        // Nothing to initialize
    }
    
    /*
    Push Operation (Costly Push)

    Goal:
    After every push, q1 should behave like stack.
    Meaning:
    The newest element must always be at front of q1.

    Steps:
    1. Push new element into q2.
    2. Move all elements from q1 into q2.
       (This places new element in front)
    3. Swap q1 and q2.
    */
    void push(int x) {

        // Step 1: Push new element into q2
        q2.push(x);

        // Step 2: Move all existing elements from q1 → q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }
    
    /*
    Pop Operation:

    Since top element is always at front of q1,
    just remove front.
    */
    int pop() {

        int val = q1.front();
        q1.pop();
        return val;
    }
    
    /*
    Top Operation:

    Front of q1 represents top of stack.
    */
    int top() {
        return q1.front();
    }
    
    /*
    Stack is empty if q1 is empty.
    */
    bool empty() {
        return q1.empty();
    }
};