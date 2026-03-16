class Solution {
public:

    // Find the row index of the maximum element in a given column
    int solve(vector<vector<int>>& mat , int col){

        int row = mat.size();

        int max_row = 0;

        // Traverse the column and find the maximum element
        for(int i = 1 ; i < row ; i++){
            if(mat[i][col] > mat[max_row][col]){
                max_row = i;
            }
        }

        return max_row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();

        int low = 0;
        int high = col - 1;

        // Binary search on columns
        while(low <= high){

            int mid = low + (high - low)/2;

            // Find the maximum element in this column
            int curr_row = solve(mat , mid);

            int left  = (mid - 1 >= 0) ? mat[curr_row][mid-1] : -1;
            int right = (mid + 1 < col) ? mat[curr_row][mid+1] : -1;

            /*
            Check if current element is greater than left and right.
            If yes → it is a peak.
            */
            if(mat[curr_row][mid] > left && mat[curr_row][mid] > right){
                return {curr_row , mid};
            }

            /*
            If left neighbor is greater,
            then a peak must exist on the left side.
            */
            else if(mat[curr_row][mid] < left){
                high = mid - 1;
            }

            /*
            If right neighbor is greater,
            then a peak must exist on the right side.
            */
            else{
                low = mid + 1;
            }
        }

        return {-1,-1};
    }
};

/*
Key Observation

Instead of searching every cell, we:

Binary search on columns
In each column, find the maximum element in that column

Why?

Because if the column maximum is not a peak, the bigger neighbor must be left or right, 
so we can move the binary search in that direction.

Why Column Maximum?
The maximum element of a column is always ≥ up and down neighbors, so we only need to check:

*/
