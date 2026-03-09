class Solution {
public:

    // Check if substring s[i...j] is palindrome
    bool isPalindrome(int i , int j , string s){

        // Base case: single char or crossed pointers
        if(i >= j) return true;

        // If characters don't match → not palindrome
        if(s[i] != s[j]) return false;

        // Move inward
        return isPalindrome(i+1 , j-1 , s);
    }

    // Backtracking function
    void solve(int idx , vector<string>& curr , vector<vector<string>>& ans , string s){

        // If we reached end of string → valid partition
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }

        // Try every possible substring starting at idx
        for(int i = idx ; i < s.length() ; i++){

            // Check if substring s[idx...i] is palindrome
            if(isPalindrome(idx , i , s)){

                // Choose this palindrome substring
                curr.push_back(s.substr(idx , i-idx+1));

                // Explore remaining string
                solve(i+1 , curr , ans , s);

                // Backtrack
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> curr;           // current partition
        vector<vector<string>> ans;    // all valid partitions

        solve(0 , curr , ans , s);

        return ans;
    }
};

// At every index, we try all possible substrings starting from that index.
// If a substring is palindrome, we choose it as one partition,
// and recursively solve the remaining string.

// After exploring that choice, we backtrack and try the next substring.