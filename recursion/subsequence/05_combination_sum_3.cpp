💡 Problem: Combination Sum III

Given:

Two integers k and n.
Use numbers 1 to 9, each at most once.

Task:
Find all unique combinations of k numbers that sum up to n.
Return all possible valid combinations in any order.

🧠 Logic (Simple Explanation)
We use backtracking to explore combinations of numbers 1 to 9.
Each number can be chosen once, so we move to i + 1 after picking a number.

Base Cases:

If n == 0 and k == 0 → valid combination found.
If n == 0 or k == 0 → stop exploring (invalid path).
For every number i from current index to 9:
Pick the number → reduce n by i, reduce k by 1.
Recurse for next index (i + 1).
Backtrack → remove the last number and try next.

🕒 Time Complexity
O(2⁹) → each number (1–9) can be picked or not picked.
Pruning reduces actual calls.

💾 Space Complexity
O(k) → recursion depth + current combination storage.

class Solution {
public:
    void solve(int idx, int k, int n, vector<int>& curr, vector<vector<int>>& ans) {
        if (n == 0 && k == 0) {
            ans.push_back(curr);
            return;
        }

        if (n == 0 || k == 0) return;

        for (int i = idx; i <= 9; i++) {
            curr.push_back(i);
            solve(i + 1, k - 1, n - i, curr, ans);
            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, k, n, curr, ans);
        return ans;
    }
};