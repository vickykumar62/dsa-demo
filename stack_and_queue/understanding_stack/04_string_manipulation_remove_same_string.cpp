class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        
        stack<string> st;

        for(int i = 0; i < arr.size(); i++){
            
            // If stack is empty → push first string
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }
            
            /*
            If current string is same as top of stack,
            it means we found consecutive duplicate.
            
            So we remove the previous one (pop).
            This cancels both.
            */
            
            if(st.top() == arr[i]) 
                st.pop();   // Remove previous duplicate
            else 
                st.push(arr[i]);  // Keep current string
        }
        
        // Remaining stack size is the final length
        return st.size();
    }
};
