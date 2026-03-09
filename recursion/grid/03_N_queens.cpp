🧩 Problem: N-Queens

Goal:
Place n queens on an n x n chessboard such that no two queens attack each other.
Queens can attack vertically, horizontally, and diagonally.
You must return all possible valid board configurations.

💡 Logic / Approach (Backtracking)

We build the board row by row.
In each row, we try to place a queen ('Q') in one of the columns.
For each placement, we check if it is valid — meaning:
No other queen is in the same column.
No other queen is in the left or right diagonal above.

Validation Check:

For every position (row, col):
Check upward column for any queen.
Check upper-left diagonal.
Check upper-right diagonal.
If any queen is found in these directions → not valid.

Backtracking:

If a placement is valid:
Place the queen ('Q'), move to the next row.
If a full valid configuration is reached (row == n) → store it.
After exploring, remove the queen ('.') to try another column.
Continue until all possibilities are explored.

🧠 Code Flow
solveNQueens(n)
│
├── Create empty board with '.'
│
└── solve(0, n, board, ans)
     ├── If row == n → store valid board
     ├── For each column in current row:
     │      ├── Check if valid position
     │      ├── Place 'Q'
     │      ├── Recurse for next row
     │      └── Backtrack (remove 'Q')

⏱️ Time & Space Complexity
Complexity	Explanation
Time: O(N!)	Each row tries multiple valid placements — roughly N × (N-1) × ... possibilities.
Space: O(N²)**	For the board (size N×N) and recursion depth.

Key Learnings:

Backtracking is perfect for exploring all possible configurations.
Always backtrack after exploring each path.
Only check upper directions, since lower rows aren't placed yet.

class Solution {
public:
    bool isvalid(int row , int col , int n , vector<string>&board ){
        // upward
        for(int i = row ; i >= 0 ; i--){
            if(board[i][col]=='Q') return false;
        }

        // upward left diagonally
        for(int i = row , j = col ; i>=0 && j>=0 ; i-- , j--){
            if(board[i][j]=='Q') return false;
        }

        // upward right diagonally
        for(int i = row , j = col ; i>=0 && j< n ; i-- , j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(int row , int n , vector<string>&board , vector<vector<string>>&ans){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col = 0 ; col < n ; col++){
            if(isvalid(row,col,n,board)){
                board[row][col] = 'Q';
                solve(row+1,n,board,ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        solve(0,n,board,ans);
        return ans;
    }
};