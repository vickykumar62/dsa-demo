// given an array check whether the subset with sum equal to target is present or not?

bool subsetSum(int index, int target, vector<int>& arr) {

    // Found subset
    if (target == 0) return true;

    // No elements left
    if (index < 0) return false;

    bool notTake = subsetSum(index - 1, target, arr);

    bool take = false;
    if (arr[index] <= target) {
        take = subsetSum(index - 1, target - arr[index], arr);
    }

    return take || notTake;
}

// memoization 
bool subsetSum(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // Base Case 1: subset found
    if (target == 0) return true;

    //  Base Case 2: no elements left
    if (index < 0) return false;

    //  Check DP (after base cases)
    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    // Not take
    bool notTake = subsetSum(index - 1, target, arr, dp);

    // Take (if possible)
    bool take = false;
    if (arr[index] <= target) {
        take = subsetSum(index - 1, target - arr[index], arr, dp);
    }

    // Store result (1 = true, 0 = false)
    return dp[index][target] = (take || notTake);
}

// bottom up
bool subsetSum(vector<int>& arr, int n, int target) {
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Base Case: sum 0 always possible
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // First element handling
    if (arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    // Fill table
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {

            // Not take
            bool notTake = dp[i - 1][t];

            // Take (if possible)
            bool take = false;
            if (arr[i] <= t) {
                take = dp[i - 1][t - arr[i]];
            }

            dp[i][t] = take || notTake;
        }
    }

    return dp[n - 1][target];
}