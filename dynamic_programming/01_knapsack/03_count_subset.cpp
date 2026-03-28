// count the number of subset present in arr
// brute force recursion approach
int countSubset(int index, int target, vector<int>& arr) {

    if (index == 0) {
    if (target == 0 && arr[0] == 0) return 2; // take or not take
    if (target == 0 || arr[0] == target) return 1;
    return 0;
    }

    // Not take
    int notTake = countSubset(index - 1, target, arr);

    // Take (if possible)
    int take = 0;
    if (arr[index] <= target) {
        take = countSubset(index - 1, target - arr[index], arr);
    }

    // Total ways
    return take + notTake;
}

// top down - momoziation
int countSubset(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {

    if (index == 0) {
    if (target == 0 && arr[0] == 0) return 2; // take or not take
    if (target == 0 || arr[0] == target) return 1;
    return 0;
    }

    if (dp[index][target] != -1) return dp[index][target];

    int notTake = countSubset(index - 1, target, arr, dp);

    int take = 0;
    if (arr[index] <= target) {
        take = countSubset(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = take + notTake;
}

// bottom up - tabualation
dp[i][t] = number of subsets using [0...i] to make sum t
At each cell: ways = ways_without_current + ways_with_current

int countSubset(vector<int>& arr, int n, int target) {
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base Case (i = 0)

    // If first element is 0:
    // We can either take it or not take it → both give sum = 0
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;   // empty subset

    // If first element is not 0 and can form its own value
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    // Fill table
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

// do the dry run of 
arr = [1, 2, 2, 3]
target = 3