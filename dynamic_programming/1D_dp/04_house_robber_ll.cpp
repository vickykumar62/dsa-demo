/* Problem: House Robber II (Circular)
Houses are in a circle
First and last house are adjacent */

/* Key Trick (INTERVIEW GOLD)

“You can’t take both first and last house together”

So break into 2 linear problems:

Case 1️: Take from [0 → n-2]
First house allowed
Last house NOT allowed
Case 2️: Take from [1 → n-1]
First house NOT allowed
Last house allowed

Final answer:

max(case1, case2) */

// recursion (brute approach)
class Solution {
public:

    // Solve House Robber I for a given range [start → end]
    int solve(int idx, int start, vector<int>& nums){

        // If we go before start → no house left
        if(idx < start) return 0;

        // Choice 1: Steal current house
        int steal = nums[idx] + solve(idx - 2, start, nums);

        // Choice 2: Skip current house
        int skip = solve(idx - 1, start, nums);

        // Return maximum profit
        return max(steal, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge case
        if(n == 1) return nums[0];

        // Case 1: [0 → n-2] (exclude last)
        int case1 = solve(n-2, 0, nums);

        // Case 2: [1 → n-1] (exclude first)
        int case2 = solve(n-1, 1, nums);

        return max(case1, case2);
    }
};

// memoization (bottom up)
class Solution {
public:

    int solve(int idx, int start, vector<int>& nums, vector<int>& dp){

        // Out of range
        if(idx < start) return 0;

        // Already computed
        if(dp[idx] != -1) return dp[idx];

        // Steal or skip
        int steal = nums[idx] + solve(idx - 2, start, nums, dp);
        int skip = solve(idx - 1, start, nums, dp);

        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        // Case 1
        vector<int> dp1(n, -1);
        int case1 = solve(n-2, 0, nums, dp1);

        // Case 2
        vector<int> dp2(n, -1);
        int case2 = solve(n-1, 1, nums, dp2);

        return max(case1, case2);
    }
};

// tabulation (top down)
class Solution {
public:

    // Helper to solve linear House Robber
    int robLinear(vector<int>& nums, int start, int end){

        // Only one house
        if(start == end) return nums[start];

        vector<int> dp(end + 1);

        // Base cases
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        // Build DP
        for(int i = start + 2; i <= end; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        // Case 1: exclude last
        int case1 = robLinear(nums, 0, n-2);

        // Case 2: exclude first
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
    }
};

// “Circle → break into two linear cases (exclude first OR exclude last)”