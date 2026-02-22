class Solution {
public:

    // Next Smaller to Right
    void solve1(vector<int>& heights, vector<int>& nsr, int n){
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--){

            /*
            IMPORTANT:
            Use >= so equal heights are popped.
            This ensures correct width for duplicate heights.
            */
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            // If no smaller element on right
            nsr[i] = st.empty() ? n : st.top();

            st.push(i);
        }
    }

    // Next Smaller to Left
    void solve2(vector<int>& heights, vector<int>& nsl, int n){
        stack<int> st;

        // Traverse from left to right
        for(int i = 0; i < n; i++){

            /*
            Again use >= for same reason.
            */
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            // If no smaller element on left
            nsl[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> nsr(n);
        vector<int> nsl(n);

        solve1(heights, nsr, n);
        solve2(heights, nsl, n);

        long long ans = 0;   // No need INT_MIN

        /*
        For every bar:
        width = (right smaller index - left smaller index - 1)
        */
        for(int i = 0; i < n; i++){
            long long height = heights[i];
            long long width = nsr[i] - nsl[i] - 1;
            ans = max(ans, height * width);
        }

        return ans;
    }
};

// optimal one pass solution 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        long long ans = 0;

        for(int i = 0; i < n; i++){

            /*
            If current height is smaller,
            calculate area for taller bars
            */
            while(!st.empty() && heights[st.top()] >= heights[i]){

                int index = st.top();
                st.pop();

                /*
                If stack empty:
                left boundary = -1
                width = i
                */
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }

                ans = max(ans, 1LL * heights[index] * width);
            }

            st.push(i);
        }

        /*
        Process remaining bars in stack
        Right boundary = n
        */
        while(!st.empty()){

            int index = st.top();
            st.pop();

            int width;
            if(st.empty()){
                width = n;
            }
            else{
                width = n - st.top() - 1;
            }

            ans = max(ans, 1LL * heights[index] * width);
        }

        return ans;
    }
};

Why width = i when stack empty?

Because stack empty means no smaller element on left.
So left boundary is -1.
Width = right - left - 1.