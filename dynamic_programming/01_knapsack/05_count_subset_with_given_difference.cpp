// recursion , handle special case arr which contain zero
int solve(int index, int target, vector<int>& arr) {

    // Base Case: only first element
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2; // take / not take
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    // Not take
    int notTake = solve(index - 1, target, arr);

    // Take (if possible)
    int take = 0;
    if (arr[index] <= target) {
        take = solve(index - 1, target - arr[index], arr);
    }

    // Total ways
    return take + notTake;
}
//memoization 
int solve(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // Base Case
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    // If already computed
    if (dp[index][target] != -1) return dp[index][target];

    int notTake = solve(index - 1, target, arr, dp);

    int take = 0;
    if (arr[index] <= target) {
        take = solve(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = take + notTake;
}
// tabulation
int countSubsetsWithDiff(vector<int>& arr, int n, int diff) {

    int totalSum = 0;
    for (int x : arr) totalSum += x;

    // Check validity
    if ((totalSum + diff) % 2 != 0) return 0;

    int target = (totalSum + diff) / 2;

    // dp[i][t] = number of ways to form sum t using [0..i]
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // -------------------------
    // Base Case (i = 0)
    // -------------------------

    if (arr[0] == 0)
        dp[0][0] = 2;   // take / not take
    else
        dp[0][0] = 1;   // empty subset

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    // -------------------------
    // Fill DP
    // -------------------------

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {

            int notTake = dp[i - 1][t];

            int take = 0;
            if (arr[i] <= t) {
                take = dp[i - 1][t - arr[i]];
            }

            dp[i][t] = take + notTake;
        }
    }

    return dp[n - 1][target];
}

// intuition 
// 1. Split array into two subsets: s1 and s2

// 2. Given:
//    s1 - s2 = diff
//    s1 + s2 = totalSum

// 3. Add both equations:
//    2*s1 = totalSum + diff

// 4. So:
//    s1 = (totalSum + diff) / 2

// 5. Problem becomes:
//    Count subsets with sum = s1

// 6. Apply Count Subset Sum DP

edge case : if ((totalSum + diff) % 2 != 0) return 0;