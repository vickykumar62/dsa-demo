class Solution {
public:
    int row;          // number of rows in grid
    int col;          // number of columns in grid
    int count_zero;   // total number of empty cells (0) that must be visited
    int ans;          // total valid paths

    void solve(int i , int j , int curr_zero_count , vector<vector<int>>& grid){

        // OUT OF BOUNDS or OBSTACLE or ALREADY VISITED
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == -1) 
            return;

        // If we reached the end cell but haven't visited all empty cells
        // then this path is invalid
        if(grid[i][j] == 2 && curr_zero_count == count_zero) 
            return;

        // VALID PATH CONDITION:
        // We reached the ending square AND
        // we have visited all zeros + starting square , that's why count_zero+1
        if(curr_zero_count == count_zero + 1 && grid[i][j] == 2){
            ans++;     // found one valid path
            return;
        }

        // STORE CURRENT VALUE
        int temp = grid[i][j];

        // MARK CURRENT CELL AS VISITED
        // (-1 means visited or obstacle)
        grid[i][j] = -1;

        // EXPLORE ALL 4 DIRECTIONS

        // Down
        solve(i + 1 , j , curr_zero_count + 1 , grid);

        // Up
        solve(i - 1 , j , curr_zero_count + 1 , grid);

        // Right
        solve(i , j + 1 , curr_zero_count + 1 , grid);

        // Left
        solve(i , j - 1 , curr_zero_count + 1 , grid);

        // BACKTRACK:
        // Restore the original value so other paths can use this cell
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        row = grid.size();
        col = grid[0].size();
        count_zero = 0;
        ans = 0;

        int start_i;
        int start_j;

        // Find:
        // 1. Number of empty cells
        // 2. Starting position
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){

                if(grid[i][j] == 0) 
                    count_zero++;

                if(grid[i][j] == 1){
                    start_i = i;
                    start_j = j;
                }
            }
        }

        // Start DFS from the starting square
        solve(start_i , start_j , 0 , grid);

        return ans;
    }
};