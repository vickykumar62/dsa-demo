🌟 Combination Sum - Recursion + Backtracking

Given an array of distinct integers (candidates) and a target,
find all unique combinations that sum up to the target.
Each number can be used unlimited times.

🧠 Logic Summary

Base Case:
Stop when sum > target.
Store the combination when sum == target.
Recursive Case:
Choose a number at index i.
Recurse again with the same i (because reuse is allowed).
Backtrack to explore other possibilities.
Why pass i and not i+1?
Passing i allows reuse of the same number (unlimited use).
Ensures combinations, not permutations by not starting the loop from 0.

class Solution {
public:
    vector<vector<int>> ans;

    // Recursive function to build combinations
    void solve(int idx, vector<int>& candidates, int target, int sum, vector<int>& curr) {
        // Base conditions
        if (sum > target) return;         // overshoot → stop
        if (sum == target) {              // found valid combination
            ans.push_back(curr);
            return;
        }

        // Try all numbers from current index onward
        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);               // choose this number
            solve(i, candidates, target, sum + candidates[i], curr); // reuse allowed → pass i
            curr.pop_back();                             // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0, candidates, target, 0, curr);
        return ans;
    }
};