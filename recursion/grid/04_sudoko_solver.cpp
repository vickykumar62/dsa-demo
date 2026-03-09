🧩 Sudoku Solver — Backtracking
🔹 Problem Statement

Given a partially filled 9×9 Sudoku board, fill the empty cells (represented by '.') so that:
Each row contains digits 1–9 without repetition.
Each column contains digits 1–9 without repetition.
Each of the nine 3×3 subgrids also contains digits 1–9 without repetition.

🔹 Intuition — “Fill and Backtrack”

Think of Sudoku solving as placing one number at a time and moving forward only if the board remains valid.
If at any point it becomes invalid, go back (backtrack) and try another number.

🔹 Approach (Step-by-Step)

Find an empty cell ('.')
Start from the top-left corner and move cell by cell.
Try placing digits '1' to '9'
For each digit, check if placing it keeps the board valid:
No duplicate in the row
No duplicate in the column
No duplicate in the 3×3 subgrid
If valid, place the number and move to the next cell.
If not valid, try the next number.
If no number fits, backtrack — reset the cell to '.' and go one step back.
Continue until the entire board is filled.

🔹 Helper Function — isvalid()

Checks whether a given character can be placed safely at (row, col):
Loops through the row and column.
Finds the top-left index of the 3×3 subgrid using:

start_row = (row / 3) * 3;
start_col = (col / 3) * 3;

Checks all 9 cells in that 3×3 grid.

🔹 Recursive Function — solve()

Base case:
If row == 9, board is fully filled → return true.

Recursive case:

Move to the next cell (next_row, next_col).
If the current cell is pre-filled, skip it.
Otherwise, try placing digits '1' to '9'.
For each valid placement → recurse forward.
If recursion fails → undo (backtrack).

🔹 Time and Space Complexity

Time Complexity: O(9^(n*n)) in the worst case
(Each cell tries up to 9 possibilities recursively)

Space Complexity: O(1)
(Solves the board in-place, uses recursion stack only)

🔹 Key Takeaways ✨

Always skip already filled cells.
Use row / 3 × 3 and col / 3 × 3 to locate subgrids.
Backtracking is just “trying everything and undoing what doesn’t work.”
Clean recursion: start from (0,0) and let recursion explore the board.

class Solution {
public:
    bool isvalid(int row , int col , char ch , vector<vector<char>>& board) {
        // Row check 
        for(int j = 0 ; j < 9 ; j++){
            if(board[row][j] == ch) return false;
        }

        // Column check
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][col] == ch) return false;
        }

        // 3x3 grid check
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;
        for(int i = start_row ; i < start_row + 3 ; i++){
            for(int j = start_col ; j < start_col + 3 ; j++){
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }

    bool solve(int row , int col , vector<vector<char>>& board) {
        if(row == 9) return true; // Solved all rows

        int next_row = row;
        int next_col = col + 1;
        if(next_col == 9){
            next_row++;
            next_col = 0;
        }

        if(board[row][col] != '.') 
            return solve(next_row, next_col, board); // Skip filled cell

        for(char ch = '1'; ch <= '9'; ch++){
            if(isvalid(row, col, ch, board)){
                board[row][col] = ch;
                if(solve(next_row, next_col, board)) return true;
                board[row][col] = '.'; // Backtrack
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};