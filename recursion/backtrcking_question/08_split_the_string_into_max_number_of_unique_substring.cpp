class Solution {
public:

    // Recursive backtracking function
    // idx  -> current index in the string from where we try to split
    // ans  -> maximum number of unique substrings found so far
    // curr -> number of substrings chosen in the current path
    // mpp  -> map to track which substrings are already used
    void solve(int idx , int &ans , int curr , unordered_map<string,int>& mpp , string s){

        // If we reached the end of the string
        // update the maximum number of unique substrings
        if(idx == s.length()){
            ans = max(ans , curr);
            return;
        }

        // Try every possible substring starting from idx
        for(int i = idx ; i < s.length() ; i++){

            // Create substring from idx to i
            string temp = s.substr(idx , i - idx + 1);

            // If this substring has not been used before
            if(mpp[temp] == 0){

                // Choose this substring
                mpp[temp]++;

                // Recurse for the remaining string
                solve(i + 1 , ans , curr + 1 , mpp , s);

                // Backtrack: remove the substring so other splits can try it
                mpp[temp]--;
            }
        }
    }

    int maxUniqueSplit(string s) {

        int ans = INT_MIN;  // stores maximum unique substrings
        int curr = 0;       // current count of substrings

        // map to track used substrings
        unordered_map<string,int> mpp;

        // start recursion from index 0
        solve(0 , ans , curr , mpp , s);

        return ans;
    }
};

// We try every possible substring starting from the current index.
// If the substring has not been used before, we:
// Add it to the set/map
// Continue splitting the rest of the string
// Backtrack and try another split
