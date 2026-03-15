class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // total rows in matrix
        int row = matrix.size();

        // total columns in matrix
        int col = matrix[0].size();

        // treat the matrix like a 1D sorted array
        int low = 0;

        // last index of the virtual array
        int high = (row * col) - 1;

        while(low <= high){

            // normal binary search mid
            int mid = low + (high - low) / 2;


            int curr_row = mid / col;
            int curr_col = mid % col;

            int value = matrix[curr_row][curr_col];

            // target found
            if(value == target) return true;

            // move right
            else if(value < target){
                low = mid + 1;
            }

            // move left
            else{
                high = mid - 1;
            }
        }

        // target not found
        return false;
    }
};

// Key Trick (Index Mapping) 
// row = mid / number_of_columns
// col = mid % number_of_columns

// Search space: 
// low  = 0
// high = (r*c) - 1
