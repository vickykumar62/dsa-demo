class Solution {
public:

    // Recursive backtracking function
    // idx   -> current position in the digits string
    // curr  -> current combination being built
    // digits -> input digits
    // mpp   -> mapping of digit to characters
    // ans   -> stores all valid combinations
    void solve(int idx , string &curr , string digits , unordered_map<char,string>& mpp , vector<string>& ans){

        // BASE CASE:
        // If we have processed all digits
        if(idx >= digits.length()){
            ans.push_back(curr); // store the formed combination
            return;
        }

        // Get current digit
        char c = digits[idx];

        // Get corresponding characters for this digit
        string s = mpp[c];

        // Try every character mapped to this digit
        for(int i = 0 ; i < s.length() ; i++){

            // Choose the character
            curr.push_back(s[i]);

            // Recurse for the next digit
            solve(idx+1 , curr , digits , mpp , ans);

            // Backtrack: remove last character
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // Mapping of digits to corresponding letters
        unordered_map<char,string> mpp;
        mpp['1'] = "";
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        string curr = "";     // current combination
        vector<string> ans;   // result container

        // Start recursion from index 0
        solve(0 , curr , digits , mpp , ans);

        return ans;
    }
};