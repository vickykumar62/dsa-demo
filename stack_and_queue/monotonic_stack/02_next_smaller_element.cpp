class Solution {
public:

    vector<int> nextSmallerElement(vector<int>& arr){

        int n = arr.size();

        // Result array
        vector<int> nse(n);

        // Stack will store elements
        stack<int> st;

        /*
        Traverse from right to left
        because we want next smaller element on right side
        */
        for(int i = n - 1; i >= 0; i--){

            /*
            Remove all elements that are greater or equal
            because they cannot be next smaller for arr[i]
            */
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }

            // If stack empty → no smaller element exists
            if(st.empty())
                nse[i] = -1;
            else
                nse[i] = st.top();

            // Push current element
            st.push(arr[i]);
        }

        return nse;
    }
};

// Next Greater → pop smaller elements
// Next Smaller → pop greater elements