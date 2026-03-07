class Solution {
public:

    // DFS + Backtracking function
    bool solve(int idx , int i , int j , 
               string word , vector<vector<char>>& board , 
               vector<vector<bool>>& visited){

        // BASE CASE:
        // If we have matched all characters of the word
        if(idx == word.length()) 
            return true;

        // OUT OF BOUNDS or ALREADY VISITED CELL
        if(i < 0 || j < 0 || 
           i >= board.size() || 
           j >= board[0].size() || 
           visited[i][j] == true)
            return false;

        // CHARACTER DOES NOT MATCH
        if(word[idx] != board[i][j]) 
            return false;

        // MARK CURRENT CELL AS VISITED
        visited[i][j] = true;

        // EXPLORE 4 DIRECTIONS

        // Down
        if(solve(idx+1 , i+1 , j , word , board , visited)) 
            return true;

        // Left
        if(solve(idx+1 , i , j-1 , word , board , visited)) 
            return true;

        // Right
        if(solve(idx+1 , i , j+1 , word , board , visited)) 
            return true;

        // Up
        if(solve(idx+1 , i-1 , j , word , board , visited)) 
            return true;

        // BACKTRACK:
        // Unmark this cell so it can be used in other paths
        visited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int row = board.size();
        int col = board[0].size();   // number of columns

        // visited matrix to track used cells
        vector<vector<bool>> visited(row , vector<bool>(col,false));

        // Try starting from every cell
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){

                // If first character matches, start DFS
                if(board[i][j] == word[0]){
                    if(solve(0 , i , j , word , board , visited))
                        return true;
                }
            }
        }

        return false;
    }
};

// solved without using extra space 
// for visited board[i][j] = '#' and while returning assign it with it's original previous val

class Solution {
public:
    bool solve(int idx , int i , int j , 
    string word , vector<vector<char>>& board){
        if(idx==word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>= board[0].size() || board[i][j]=='#') return false;
        if(word[idx] != board[i][j]) return false;
        

        char c = board[i][j];
        board[i][j] = '#';

       if( solve(idx+1,i+1,j,word,board) ) return true; // d 
       if( solve(idx+1,i,j-1,word,board) ) return true; // l
       if( solve(idx+1,i,j+1,word,board) ) return true; // r
       if( solve(idx+1,i-1,j,word,board) ) return true; //u
       
        board[i][j] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j]==word[0]){
                    if (solve(0,i,j,word,board) ) return true;
                }
            }
        }
        return false;
        
    }
};