class Solution {

public:
    vector<int> nextGreaterElement(vector<int>& arr){
        
        int n = arr.size();
        
        // Initialize result array with size n
        vector<int> nge(n);
        
        // Stack will store elements (not indices here)
        stack<int> st;

        /*
        Traverse from right to left
        Because we want next greater element on right side
        */
        for(int i = n - 1; i >= 0; i--){
            
            /*
            Remove all elements from stack
            that are smaller or equal to current element
            Because they can never be NGE for this element
            */
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }

            // If stack empty → no greater element on right
            if(st.empty()) 
                nge[i] = -1;
            else 
                nge[i] = st.top();

            // Push current element into stack
            st.push(arr[i]);
        }

        return nge;
    }
};
