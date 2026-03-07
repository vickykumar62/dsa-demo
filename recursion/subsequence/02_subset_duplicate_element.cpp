🧠 Subsets II (Handling Duplicates)
💡 Goal
Given an array nums (which may contain duplicates), return all possible unique subsets — the power set without repetition.

🔹 Key Idea — Sorting + Skip Duplicates
When duplicates exist (like [1, 2, 2]), recursion may generate the same subset twice.
So, we sort the array first, and skip consecutive duplicates inside the same recursive level.

🔹 Logic Flow
Sort the array — so duplicates come together.
Use a for loop to explore elements starting from idx.

Before recursion:
If i > idx && nums[i] == nums[i - 1], skip this element (it’s a duplicate at this level).
Push the current element → recurse → pop to backtrack.

⚙️ Complexity (in simple words)
Each number can either be picked or not → around 2ⁿ subsets.
Sorting helps in skipping duplicates efficiently.
🕒 Time: O(2ⁿ × n)
💾 Space: O(n)

class Solution {
public:
    void solve(int idx, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        ans.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > idx && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            solve(i + 1, curr, ans, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Important step
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, nums);
        return ans;
    }
};