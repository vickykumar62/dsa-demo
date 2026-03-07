💡 Problem: Combination Sum II

Given:
An array of integers candidates (may contain duplicates) and a target value target.

Task:
Find all unique combinations in candidates where the numbers add up to target.
Each number can be used only once in a combination.
The answer must not contain duplicate combinations.

🧠 Logic (Simple Explanation)

Sort the array — to easily skip duplicates.
Use backtracking to explore all possible combinations.
For every number, we have two choices:
Pick it → add to current sum and move to next index (i + 1).
Skip it → move to next index without picking.
Avoid duplicates by checking:

if(i > idx && candidates[i] == candidates[i - 1]) continue;

→ Skip same numbers at the same recursion level.

Stop exploring when:
sum > target → overshoot (stop path).
sum == target → valid combination found → add to answer.

class Solution {
public:
    void solve(int idx, int sum, int target, vector<int>& curr, 
               vector<vector<int>>& ans, vector<int>& candidates) {

        if(sum > target) return;
        if(sum == target) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            curr.push_back(candidates[i]);
            solve(i + 1, sum + candidates[i], target, curr, ans, candidates);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(0, 0, target, curr, ans, candidates);
        return ans;
    }
};


Sorting takes O(n log n) initially.

💾 Space Complexity

O(n) → recursion + current combination storage.