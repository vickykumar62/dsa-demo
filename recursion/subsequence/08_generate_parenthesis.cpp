class Solution {
public:

    // Backtracking function
    // curr  -> current string being built
    // open  -> number of '(' used so far
    // close -> number of ')' used so far
    void solve(vector<string>& ans , string &curr , int n , int open , int close){

        // BASE CASE:
        // When the length becomes 2*n, we have used all parentheses
        if(curr.length() == (n * 2)){
            ans.push_back(curr);   // valid combination formed
            return;
        }

        // CHOICE 1: Add '('
        // We can add '(' only if we still have remaining open brackets
        if(open < n){
            curr += "(";                       // choose
            solve(ans , curr , n , open+1 , close); // explore
            curr.pop_back();                   // backtrack (remove last added char)
        }

        // CHOICE 2: Add ')'
        // We can add ')' only if closing brackets are less than opening
        // This ensures the parentheses remain valid
        if(close < open){
            curr += ")";                       // choose
            solve(ans , curr , n , open , close+1); // explore
            curr.pop_back();                   // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;   // stores all valid combinations
        string curr = "";     // current building string

        int open = 0;         // number of '(' used
        int close = 0;        // number of ')' used

        // start recursion
        solve(ans , curr , n , open , close);

        return ans;
    }
};

// We cannot add more than n opening brackets
// We cannot close more than we opened