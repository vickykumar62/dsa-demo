class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        
        // We cannot directly access the bottom of stack
        // because stack only allows access to top element.
        
        stack<int> temp;

        // Step 1: Remove all elements from original stack
        // and store them in a temporary stack
        while(!st.empty()){
            temp.push(st.top());  // Save top element
            st.pop();             // Remove it from original stack
        }
        
        // Step 2: Now original stack is empty
        // So we can safely push x (it will be at bottom later)
        st.push(x);
        
        // Step 3: Push back all elements from temp stack
        // This restores original order above x
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        
        return st;
    }
};

// optimal

void insertAtBottom(stack<int>& st, int x) {
    if(st.empty()){
        st.push(x);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    
    insertAtBottom(st, x);  // Reach bottom
    
    st.push(topElement);    // Restore elements
}
