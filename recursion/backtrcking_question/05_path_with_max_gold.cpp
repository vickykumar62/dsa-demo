class Solution {
public:
    int row;  // number of rows in the grid
    int col;  // number of columns in the grid

    // DFS + Backtracking function
    // i, j        -> current cell
    // curr_gold   -> gold collected so far in this path
    // max_gold    -> maximum gold found among all paths
    void solve(int i , int j , int curr_gold , int &max_gold , vector<vector<int>>& grid){

        // Base condition:
        // If out of bounds OR cell has no gold (0) → stop exploring this path
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0) 
            return;

        // Store the current cell's gold value
        int temp = grid[i][j];

        // Mark this cell as visited by setting it to 0
        // This prevents revisiting the same cell in the same path
        grid[i][j] = 0;

        // Add the gold of this cell to the current path
        curr_gold += temp;

        // Update the maximum gold collected so far
        max_gold = max(max_gold , curr_gold);

        // Explore all 4 possible directions

        solve(i+1 , j , curr_gold , max_gold , grid); // move down
        solve(i-1 , j , curr_gold , max_gold , grid); // move up
        solve(i , j+1 , curr_gold , max_gold , grid); // move right
        solve(i , j-1 , curr_gold , max_gold , grid); // move left

        // Backtrack:
        // Restore the original gold value so other paths can use this cell
        grid[i][j] = temp;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        row = grid.size();      // total rows
        col = grid[0].size();   // total columns

        int max_gold = 0;       // stores the best path result

        // Try starting the DFS from every cell containing gold
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){

                // If the cell contains gold, start exploring
                if(grid[i][j] != 0){
                    solve(i , j , 0 , max_gold , grid);
                }
            }
        }

        // Return the maximum gold collected among all possible paths
        return max_gold;
    }
};