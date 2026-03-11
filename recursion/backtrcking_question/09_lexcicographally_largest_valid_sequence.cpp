class Solution {
public:

    // Backtracking function
    // idx  -> current index we are trying to fill in ans
    // n    -> maximum number
    // used -> tracks which numbers are already placed
    // ans  -> resulting sequence
    bool solve(int idx , int n , vector<bool>& used , vector<int>& ans){

        // If we filled all positions successfully
        if(idx == ans.size()) return true;

        // If current position already filled, skip to next
        if(ans[idx] != -1) return solve(idx+1 , n , used , ans);

        // Try numbers from largest to smallest
        // This ensures lexicographically largest result
        for(int i = n ; i > 0 ; i--){

            // If number already used, skip it
            if(used[i] == true) continue;

            // Case 1: number > 1 (must appear twice)
            if(i != 1){

                // Second position must be i distance away
                int j = idx + i;

                // Check if second position is valid and empty
                if(j < ans.size() && ans[j] == -1){

                    // Place the number in both positions
                    used[i] = true;
                    ans[idx] = i;
                    ans[j] = i;

                    // Recurse to fill next positions
                    if(solve(idx+1 , n , used , ans)) return true;

                    // Backtrack
                    ans[idx] = -1;
                    ans[j] = -1;
                    used[i] = false;
                }
            }

            // Case 2: number = 1 (only appears once)
            else{
                used[i] = true;
                ans[idx] = i;

                if(solve(idx+1 , n , used , ans)) return true;

                // Backtrack
                used[i] = false;
                ans[idx] = -1;
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {

        // Result array size = 2*n - 1
        vector<int> ans(2*n - 1 , -1);

        // Track which numbers are used
        vector<bool> used(n + 1 , false);

        solve(0 , n , used , ans);

        return ans;
    }
};

// At each index:
// Try placing a number
// Mark it as used
// Recurse to fill the next index
// If it fails → undo placement (backtrack)