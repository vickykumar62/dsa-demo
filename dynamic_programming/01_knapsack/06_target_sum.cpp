// intuition
// 1. Each number gets + or -

// 2. Think:
//    positives → subset s1
//    negatives → subset s2

// 3. So:
//    s1 - s2 = target
//    s1 + s2 = totalSum

// 4. Add equations:
//    2*s1 = totalSum + target

// 5. So:
//    s1 = (totalSum + target)/2

// 6. Problem becomes:
//    Count subsets with sum = s1

 edge case : if ((totalSum + target) % 2 != 0) return 0;

 // recursion 
 int solve(int index, int target, vector<int>& arr) {

    // Base Case
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    int notTake = solve(index - 1, target, arr);

    int take = 0;
    if (arr[index] <= target) {
        take = solve(index - 1, target - arr[index], arr);
    }

    return take + notTake;
}
//memoization
int solve(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {

    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    if (dp[index][target] != -1) return dp[index][target];

    int notTake = solve(index - 1, target, arr, dp);

    int take = 0;
    if (arr[index] <= target) {
        take = solve(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = take + notTake;
}
//tabulation
int findTargetSumWays(vector<int>& nums, int target) {

    int totalSum = 0;
    for (int x : nums) totalSum += x;

    if ((totalSum + target) % 2 != 0) return 0;

    int newTarget = (totalSum + target) / 2;

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(newTarget + 1, 0));

    // Base Case
    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] != 0 && nums[0] <= newTarget)
        dp[0][nums[0]] = 1;

    // Fill DP
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= newTarget; t++) {

            int notTake = dp[i - 1][t];

            int take = 0;
            if (nums[i] <= t) {
                take = dp[i - 1][t - nums[i]];
            }

            dp[i][t] = take + notTake;
        }
    }

    return dp[n - 1][newTarget];
}