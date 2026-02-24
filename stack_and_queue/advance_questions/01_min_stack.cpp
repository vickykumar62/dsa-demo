class MinStack {
public:

    /*
    Stack stores:
    { value, minimum value till this element }
    
    So at every position we know:
    - current element
    - minimum of all elements below (including itself)
    */
    stack<pair<int,int>> st;

    MinStack() {
        // Nothing to initialize
    }
    
    void push(int val) {

        /*
        If stack is empty:
        current value itself is minimum.
        */
        if(st.empty()){
            st.push({val, val});
        }
        else{
            /*
            Compare current value with previous minimum.
            Store the smaller one as new minimum.
            */
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        // Simply remove top element
        if(!st.empty())
            st.pop();
    }
    
    int top() {
        /*
        Return the value part of the pair.
        */
        if(st.empty()) return -1;  // optional safeguard
        return st.top().first;
    }
    
    int getMin() {
        /*
        Return the minimum stored at this level.
        */
        if(st.empty()) return -1;  // optional safeguard
        return st.top().second;
    }
};


// optimal in o(1) space 

class MinStack {
public:

    /*
    We store values in a single stack.
    But when a new minimum appears,
    we push an encoded value instead.

    min_val always stores current minimum.
    */
    long long min_val;
    stack<long long> st;

    MinStack() {
        // Nothing required here
    }
    
    void push(int val) {

        if(st.empty()){
            // First element → it is minimum
            st.push(val);
            min_val = val;
        }
        else{
            if(val > min_val){
                // Normal case → just push value
                st.push(val);
            }
            else{
                /*
                New minimum found.

                We encode previous minimum into stack using:
                encoded_value = 2*val - min_val

                Then update min_val to val.
                */
                st.push(2LL * val - min_val);
                min_val = val;
            }
        }
    }
    
    void pop() {

        /*
        If top > min_val → normal value
        If top <= min_val → encoded value
        */

        if(st.top() > min_val){
            st.pop();
        }
        else{
            /*
            This means top is encoded value.

            We need to restore previous minimum using:

            previous_min = 2*current_min - encoded_value
            */
            min_val = 2LL * min_val - st.top();
            st.pop();
        }
    }
    
    int top() {

        /*
        If top > min_val → normal value
        If top <= min_val → encoded value
            → actual value is min_val
        */

        if(st.top() > min_val)
            return st.top();
        else
            return min_val;
    }
    
    int getMin() {
        return min_val;
    }
};