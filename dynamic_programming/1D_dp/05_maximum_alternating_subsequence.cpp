/* Problem: Maximum Alternating Subsequence Sum
Pick a subsequence such that:
+ nums[i1] - nums[i2] + nums[i3] - nums[i4] ...
Maximize this sum */

/* STATE DEFINITION (KEY STEP)

solve(idx, even)
idx → current index
even → are we at even position in subsequence?
even = true → next pick will be +
even = false → next pick will be -

RECURRENCE
Take:
    if even → +nums[idx]
    else    → -nums[idx]

Skip:
    do nothing */

// recursion
class Solution {
public:

    long long solve(int idx, bool even, vector<int>& nums){

        // No elements left
        if(idx < 0) return 0;

        // Choice 1: skip current element
        long long skip = solve(idx - 1, even, nums);

        // Choice 2: take current element
        long long take;
        if(even){
            // Even position → add
            take = nums[idx] + solve(idx - 1, !even, nums);
        } else {
            // Odd position → subtract
            take = -nums[idx] + solve(idx - 1, !even, nums);
        }

        return max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        // Start with even = true → first pick is positive
        return solve(n - 1, true, nums);
    }
};

// memoization (top down)
class Solution {
public:

    // solve(idx, even)
    // idx  → current index
    // even → true  → next picked element will be '+'
    //         false → next picked element will be '-'
    long long solve(int idx, bool even, vector<int>& nums, vector<vector<long long>>& dp){

        // Base case:
        // No elements left → contribution = 0
        if(idx < 0) return 0;

        // If already computed, return stored result
        if(dp[idx][even] != -1) return dp[idx][even];

        // Choice 1: Skip current element
        // → state (even/odd) remains same
        long long skip = solve(idx - 1, even, nums, dp);

        // Choice 2: Take current element
        long long take;

        if(even){
            // If even → we ADD current number
            // Next state becomes odd (sign flips)
            take = nums[idx] + solve(idx - 1, false, nums, dp);
        } else {
            // If odd → we SUBTRACT current number
            // Next state becomes even
            take = -nums[idx] + solve(idx - 1, true, nums, dp);
        }

        // Store and return the best of both choices
        return dp[idx][even] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        // dp[idx][even]
        // even = 0 → false (next sign '-')
        // even = 1 → true  (next sign '+')
        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        // Start from last index
        // even = true → first picked element will be '+'
        return solve(n - 1, true, nums, dp);
    }
};
// “At each index → either skip OR take with +/− depending on turn, then flip state”


