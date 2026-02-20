class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> nge(n);     // Store answer
        stack<int> st;          // Monotonic decreasing stack

        /*
        Traverse from 2*n - 1 to 0
        Why?
        - First pass (i >= n) builds the stack
        - Second pass (i < n) fills answers
        */
        for(int i = 2*n - 1 ; i >= 0 ; i--){

            // Maintain decreasing stack
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }

            /*
            Only fill answer in second pass
            (when i < n)
            */
            if(i < n){
                nge[i] = st.empty() ? -1 : st.top();
            }

            // Push current element
            st.push(nums[i % n]);
        }

        return nge;
    }
};

we simulate circular behavior by iterating:
from 2*n - 1 → 0

And access elements using:
nums[i % n]

If interviewer says:
“Circular array”

Traverse 2*n
Use i % n
