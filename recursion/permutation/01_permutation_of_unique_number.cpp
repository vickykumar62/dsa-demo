🧠 Permutations (All Possible Arrangements)
💡 Goal
Given an array nums, return all possible permutations — different ways to arrange all elements.
Example:
[1, 2, 3] → [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]

🔹 Core Idea
At each step:
Pick one element that hasn’t been used yet.
Add it to the current permutation.
Recurse for the remaining elements.
Then backtrack (remove it) and try another choice.
We keep a set (st) to track which elements are already used in the current path.

⚙️ Complexity (Simple Terms)
Total permutations: n!
Each permutation takes O(n) to build.
🕒 Time: O(n × n!)
💾 Space: O(n) (for recursion + tracking used elements)

class Solution {
public:
    void solve(int n, unordered_set<int>& used, vector<int>& curr,
               vector<vector<int>>& ans, vector<int>& nums) {
        // Base case: one full permutation is ready
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        // Try placing each unused number
        for (int i = 0; i < n; i++) {
            if (used.find(nums[i]) == used.end()) {
                used.insert(nums[i]);           // mark as used
                curr.push_back(nums[i]);        // choose
                solve(n, used, curr, ans, nums); // recurse
                curr.pop_back();                // undo (backtrack)
                used.erase(nums[i]);            // unmark
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_set<int> used;
        int n = nums.size();

        solve(n, used, curr, ans, nums);
        return ans;
    }
};

METHOD 2

🔹 Approach
Use a visited vector of size n initialized to false,
to mark whether a number is already used in the current permutation.
Maintain a temporary list curr to build the permutation.
For each element in nums:
If it’s not visited, include it in curr and mark it visited.
Recur to fill the next position.
Backtrack (remove it and mark it unvisited again).
Once the size of curr equals n, we’ve formed a complete permutation → add it to the result.

🔹 Time Complexity
O(n × n!) — There are n! permutations, and building each takes O(n) time.

🔹 Space Complexity
O(n) — For recursion stack and visited array.

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue; // skip if number already used

            visited[i] = true;
            curr.push_back(nums[i]);
            solve(nums, curr, ans, visited);
            curr.pop_back();
            visited[i] = false; // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        solve(nums, curr, ans, visited);
        return ans;
    }
};