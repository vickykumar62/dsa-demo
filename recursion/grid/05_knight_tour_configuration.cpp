class Solution {
public:
    int n;

    // Checks if (i, j) is within bounds and is the next correct move
    bool isvalid(vector<vector<int>>& grid, int i, int j, int nextMove) {
        return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == nextMove);
    }

    // Try to verify the knight's path by checking one move at a time
    bool solve(int i, int j, int count, vector<int>& row, vector<int>& col, vector<vector<int>>& grid) {
        if (count == n * n - 1) return true; // All cells visited correctly

        int nextMove = count + 1;

        for (int k = 0; k < 8; k++) {
            int nrow = i + row[k];
            int ncol = j + col[k];
            if (isvalid(grid, nrow, ncol, nextMove)) {
                if (solve(nrow, ncol, nextMove, row, col, grid)) return true;
            }
        }

        return false; // No valid knight move found for the next move
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        
        // The knight must start at (0,0)
        if (grid[0][0] != 0) return false;

        vector<int> row = {-2, -1, 1, 2, 2, 1, -1, -2};
        vector<int> col = {1, 2, 2, 1, -1, -2, -2, -1};

        return solve(0, 0, 0, row, col, grid);
    }
};


