class Solution {
public:

    vector<int> previousSmallerElement(vector<int>& arr){

        int n = arr.size();

        vector<int> pse(n);     // To store previous smaller elements

        stack<int> st;          // Monotonic increasing stack

        /*
        Traverse from left to right
        because we want previous (left side) smaller element
        */
        for(int i = 0; i < n; i++){

            /*
            Remove all elements greater than or equal to current,
            because they cannot be previous smaller
            */
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }

            // If stack empty → no smaller element on left
            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();   // Top is nearest smaller element

            // Push current element for future comparisons
            st.push(arr[i]);
        }

        return pse;
    }
};
