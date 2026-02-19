class solution{
    vector<int> previousGreaterSolution(vector<int>&arr){
        int n = arr.size();
        vector<int> pge(n);      // To store previous greater elements
        stack<int> st;          // Monotonic decreasing stack

        for(int i = 0 ; i < n ; i++){

            // Remove all elements smaller than or equal to current
            // Because they can never be previous greater
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }

            // If stack empty → no greater element on left
            if(st.empty()) 
                pge[i] = -1;
            else 
                pge[i] = st.top();   // Top is nearest greater element

            // Push current element for future elements
            st.push(arr[i]);
        }
        return pge;
    }
};
