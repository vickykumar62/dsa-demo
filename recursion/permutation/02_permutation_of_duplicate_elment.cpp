🧩 Permutation II — Unique Permutations (Leetcode 47)
🔍 Problem Description
Given an array nums that may contain duplicate elements, return all unique permutations of nums.
The answer can be returned in any order.

💡 Approach (Backtracking with Sorting + Used Array)
Sort the array → so that duplicate elements come next to each other.
Use a boolean used[] array to track which indices are already part of the current permutation.

At every recursive step:
Skip any element already used.
Skip a duplicate element if it’s the same as the previous and the previous is not yet used (!used[i-1]).

🔍 Why this works:
Let’s say your sorted array is:
nums = [1, 1, 2]
indexes: 0  1  2
Now — both nums[0] and nums[1] are 1.
We only want unique permutations, not duplicates like [1,1,2] twice.
When generating permutations:
At the beginning, we want to use the first 1 before the second 1.
So, if the previous identical element (nums[i-1]) hasn’t been used,
that means we’re trying to use the later duplicate first — which would create a duplicate permutation.

When the current permutation’s length equals nums.size(), add it to the result.
Backtrack by removing the last added element and marking it unused again.

🧠 Intuition
Sorting + the duplicate-skip condition ensures each unique number is chosen in a specific order,
so no duplicate permutations are generated.

🧮 Time Complexity
O(N × N!) → each of the N! permutations takes O(N) time to copy.
Sorting adds O(N log N) (negligible compared to N!).

💾 Space Complexity
O(N) → recursion stack + used[] array.

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            solve(nums, curr, ans, used);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        solve(nums, curr, ans, used);
        return ans;
    }
};

! important 
🔹 Handling Duplicates in Backtracking

1️⃣ Combination / Subset (order doesn’t matter)

if (i > start && nums[i] == nums[i - 1]) continue;
→ Skip duplicates appearing at the same recursion level.
→ Ensures unique combinations like [1,2], not [1,2] & [2,1].

2️⃣ Permutation (order matters)

if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
→ Allow a duplicate only if its previous copy is already used.
→ Prevents duplicate permutations caused by swapping identical values.
we are using the !used[i-1] because every time we are running the loop from the 0

Summary:

Combination: skip same value at same level.
Permutation: skip same value if previous duplicate not used yet.