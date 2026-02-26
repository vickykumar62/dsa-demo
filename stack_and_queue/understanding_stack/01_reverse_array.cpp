class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // Stack follows LIFO (Last In First Out)
        // So if we push all characters into stack,
        // they will come out in reverse order.
        
        stack<char> st;

        // Step 1: Push all characters into stack
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);   // Store each character
        }

        // Step 2: Pop characters and overwrite original vector
        int j = 0;
        while(!st.empty()){
            s[j] = st.top();   // Get top element (last inserted)
            st.pop();          // Remove it
            j++;               // Move to next index
        }
    }
};
