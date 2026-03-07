💡 Problem: Combination Sum IV

Given:
An integer array nums (with distinct positive integers) and a target integer target.

Task:
Find the total number of possible combinations that sum up to target.
You can use each number from nums unlimited times.
The order of numbers matters — [1,2] and [2,1] are counted separately.

🧠 Logic (Simple & Clear)

We use recursion to build combinations starting from sum = 0.
At each step, we try adding every number from nums.

Base Cases:

If sum > target → overshoot → stop exploring that path.
If sum == target → valid combination found → increment count.
The for loop starts from i = 0 every time because:
Each number can be used multiple times, and
The order matters, so we must explore all numbers again at each step.
Example: after choosing 1, we can still choose 1, 2, or 3 again.
Hence, we don’t move to the next index like in “combination” problems (where order doesn’t matter).

class Solution {
public:
    void solve(int sum, int target, int& ans, vector<int>& nums) {
        if(sum > target) return;          // stop if sum exceeds target
        if(sum == target) {               // valid combination found
            ans++;
            return;
        }

        for(int i = 0; i < nums.size(); i++) { // start from 0 every time
            solve(sum + nums[i], target, ans, nums);
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        solve(0, target, ans, nums);
        return ans;
    }
};

