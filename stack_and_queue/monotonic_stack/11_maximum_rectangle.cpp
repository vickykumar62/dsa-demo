class Solution {
public:

    /*
    This function calculates largest rectangle in histogram
    using monotonic increasing stack (one-pass optimal solution).
    */
    long long largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;      // stores indices (monotonic increasing heights)
        long long ans = 0;

        for(int i = 0; i < n; i++){

            /*
            If current height is smaller than top of stack,
            it means the bar at stack top cannot extend further right.
            So we pop and calculate its area.
            */
            while(!st.empty() && heights[st.top()] >= heights[i]){

                int index = st.top();  // index of bar whose area we finalize
                st.pop();

                /*
                After popping:
                - Right boundary = i (current index)
                - Left boundary = st.top() (if exists)
                - If stack empty → no smaller on left → left = -1
                */

                int width;

                if(st.empty()){
                    // No smaller element on left
                    width = i;   // i - (-1) - 1
                }
                else{
                    // Nearest smaller on left is st.top()
                    width = i - st.top() - 1;
                }

                ans = max(ans, 1LL * heights[index] * width);
            }

            // Push current index for future calculations
            st.push(i);
        }

        /*
        Now process remaining elements in stack.
        For these elements:
        - No smaller element exists on right.
        - So right boundary = n.
        */
        while(!st.empty()){

            int index = st.top();
            st.pop();

            int width;

            if(st.empty()){
                // No smaller element on left
                width = n;  // n - (-1) - 1
            }
            else{
                width = n - st.top() - 1;
            }

            ans = max(ans, 1LL * heights[index] * width);
        }

        return ans;
    }


    /*
    Main function for Maximal Rectangle in Binary Matrix.

    Idea:
    - Treat each row as the bottom of a histogram.
    - heights[j] stores number of consecutive 1's above (including current row).
    - For each row, compute largest rectangle in histogram.
    */
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Edge case: empty matrix
        if(matrix.empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        long long ans = 0;

        // This array represents histogram heights
        vector<int> heights(col, 0);

        /*
        Traverse row by row.
        For each row:
        - Update histogram heights.
        - Compute largest rectangle for that histogram.
        */
        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){

                if(matrix[i][j] == '0'){
                    // If cell is 0, rectangle breaks
                    heights[j] = 0;
                }
                else{
                    // If cell is 1, increase height
                    heights[j] += 1;
                }
            }

            // Calculate max rectangle for current histogram
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};