/* Problem: House Robber
You cannot rob adjacent houses
Maximize the money you can steal */

/* CORE INTUITION (MOST IMPORTANT)
At every house i, you have 2 choices:

Steal current house
Then you must skip previous
Profit = nums[i] + f(i-2)

Skip current house
Move to previous
Profit = f(i-1) 

f(i) = max(
    nums[i] + f(i-2),   // steal
    f(i-1)              // skip
) 
    */

/* RECURSION (Brute Force)
Intuition

Try both choices at every index*/

class Solution {
public:

    int solve(int idx , vector<int> &nums){

        // Base case: no house left
        if(idx < 0) return 0;

        // Choice 1: Steal current house
        int steal = nums[idx] + solve(idx - 2, nums);

        // Choice 2: Skip current house
        int skip = solve(idx - 1, nums);

        // Take maximum profit
        return max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int idx = nums.size() - 1;

        return solve(idx, nums);
    }
};

/* MEMOIZATION (Top-Down DP)
Intuition

“If I already computed max profit till idx → reuse it”*/

class Solution {
public:

    int solve(int idx , vector<int> &nums , vector<int>& dp){

        // No house left
        if(idx < 0) return 0;

        // Already computed
        if(dp[idx] != -1) return dp[idx];

        // Steal current
        int steal = nums[idx] + solve(idx - 2, nums, dp);

        // Skip current
        int skip = solve(idx - 1, nums, dp);

        // Store result
        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(n - 1, nums, dp);
    }
};

/* TABULATION (Bottom-Up)
Intuition

“Build answer from left → right using previous results”*/

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge cases
        if(n == 1) return nums[0];

        // dp[i] = max profit till house i
        vector<int> dp(n);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Build solution
        for(int i = 2; i < n; i++){

            // Steal current OR skip
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
};