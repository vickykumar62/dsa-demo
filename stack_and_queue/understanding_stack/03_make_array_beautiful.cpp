class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
            
            // If stack is empty → just push
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }
            
            /*
            If top element and current element have opposite signs:
            
            Case 1: top >= 0  AND current < 0
            Case 2: top < 0   AND current >= 0
            
            That means one is positive and other is negative.
            So they cancel each other → remove top.
            */
            
            if( (st.top() >= 0 && arr[i] < 0) ||
                (st.top() < 0 && arr[i] >= 0) )
            {
                st.pop();   // Cancel previous element
            }
            else{
                // Same sign → no cancellation → push
                st.push(arr[i]);
            }
        }
        
        // Stack stores result in reverse order
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        // Reverse to restore original order
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


Problem involves: Removing adjacent elements , Comparing with previous element only
We only care about: Current element , Last valid element

Stack Cancellation Pattern

Current element interacts only with previous valid element.

