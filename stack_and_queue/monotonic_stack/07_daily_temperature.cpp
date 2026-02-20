class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> ans(n);   // Stores number of days to wait

        // Stack stores {temperature, index}
        // Monotonic decreasing stack
        stack<pair<int,int>> st;

        /*
        Traverse from right to left
        Because we want next warmer day
        */
        for(int i = n-1 ; i >= 0 ; i--){

            /*
            Remove all temperatures that are
            less than or equal to current temperature
            because they cannot be the answer
            */
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            /*
            If stack empty → no warmer day
            Else → difference of indices
            */
            ans[i] = st.empty() ? 0 : st.top().second - i;

            // Push current day
            st.push({temperatures[i], i});
        }

        return ans;
    }
};

distance = nextIndex - currentIndex
