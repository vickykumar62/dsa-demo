class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        /*
        mpp will store:
        element -> its next greater element in nums2
        */
        unordered_map<int,int> mpp;

        stack<int> st;

        int n2 = nums2.size();

        /*
        Step 1:
        Build Next Greater Element mapping for nums2
        using Monotonic Decreasing Stack
        */
        for(int i = n2 - 1; i >= 0; i--){

            // Remove all elements smaller or equal to nums2[i]
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            // If stack empty → no greater element
            if(st.empty()) 
                mpp[nums2[i]] = -1;
            else 
                mpp[nums2[i]] = st.top();

            // Push current element as candidate
            st.push(nums2[i]);
        }

        /*
        Step 2:
        Build answer for nums1 using the map
        */
        int n1 = nums1.size();
        vector<int> ans(n1, -1);

        for(int i = 0; i < n1; i++){
            ans[i] = mpp[nums1[i]];
        }

        return ans;
    }
};
