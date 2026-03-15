class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        // Start from the top-right corner
        int curr_row = 0;
        int curr_col = col - 1;

        /*
        Why top-right?

        From this position:
        left  → values decrease
        down  → values increase

        So we can eliminate either a row or a column in one step
        */

        while(curr_col >= 0 && curr_row < row){ 

            // if target found
            if(matrix[curr_row][curr_col] == target)
                return true;

            // current value is larger than target
            // move left to reduce the value
            else if(matrix[curr_row][curr_col] > target)
                curr_col--;

            // current value is smaller than target
            // move down to increase the value
            else
                curr_row++;
        }

        // target not present in matrix
        return false;
    }
};

// Intuition :

// The matrix has this property: 
// 1. Each row is sorted (left → right)
// 2. Each column is sorted (top → bottom)

// Notice:

// Moving right → values increase
// Moving down → values increase

// So we must start from a position where we can eliminate a row or column in one step.

// The best position is:
// top-right corner

// because:
// left  → smaller
// down  → larger

// This gives us a decision direction.

// Case 1
// matrix[row][col] > target

// Current value too large.

// Since column is sorted:

// everything below is larger

// So we move left.

// col--

// Case 3
// matrix[row][col] < target

// Current value too small.

// Since row is sorted:

// everything left is smaller

// So we move down.

// row++