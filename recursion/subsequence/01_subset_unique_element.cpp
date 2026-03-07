📖 The Story of Subsets

Goal:
Given an array of unique numbers, find all possible subsets (the power set).

Example:
For nums = [1, 2],
All subsets are: [ ] , [1] , [2] , [1, 2].

🧩 The Three Parts of the Recursion Story

1 .  Base Case (The Ending)
When idx >= n, it means we’ve made decisions for all elements.
So, we add the current subset (curr) to the answer list.

2 . Recursive Step (The Chapter Progression)
At each ndex:
Include the current number → move to next index.
Exclude the current number → move to next index again.

3 . Leap of Faith (The Trust)
We trust recursion to handle both possibilities —
one where the current element is taken, and one where it’s not.

⚙️ Complexity (in Simple Words)
Every element has 2 choices → include or exclude.
So total subsets = 2ⁿ.
🕒 Time Complexity: O(2ⁿ × n) → (n for copying each subset)
💾 Space Complexity: O(n) → (for recursive stack and current subset)

💡 Key Takeaway

Subset generation is a story of decisions —
at each step, recursion explores both “include” and “exclude” paths.
The power of recursion lies in trusting it to explore all possibilities.

class Solution { 
public:
    void subset(int idx, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums, int n) {
        if (idx >= n) {                // Base case
            ans.push_back(curr);
            return;
        }

        // Include current element
        curr.push_back(nums[idx]);
        subset(idx + 1, curr, ans, nums, n);

        // Exclude current element
        curr.pop_back();
        subset(idx + 1, curr, ans, nums, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        subset(0, curr, ans, nums, n);
        return ans;
    }
};


🧠 Understanding the “for loop” version of Subset Generation

In this version, recursion explores choices ahead using a loop —
it says:
“At each level, pick one element and move forward to build subsets starting from it.”
It’s like saying:
“I’ll fix one element, then recursively find all subsets starting after it.”


class Solution {
public:
    void helper(int start, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        // Always push current subset (every path is a valid subset)
        ans.push_back(curr);

        // Explore all choices starting from 'start'
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);          // include current element
            helper(i + 1, curr, ans, nums);   // move forward
            curr.pop_back();                  // backtrack to explore next choice
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, curr, ans, nums);
        return ans;
    }
};