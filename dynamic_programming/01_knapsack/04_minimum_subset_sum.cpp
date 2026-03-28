// brute force - recursion
// try all subset sum 
// track currSum
// calculate the difference

int solve(int index, int currSum, int totalSum, vector<int>& arr) {

    // Base Case: no elements left
    if (index < 0) {
        int s1 = currSum;
        int s2 = totalSum - currSum;

        // Return difference
        return abs(s1 - s2);
    }

    // Choice 1: TAKE element
    int take = solve(index - 1, currSum + arr[index], totalSum, arr);

    // Choice 2: NOT TAKE
    int notTake = solve(index - 1, currSum, totalSum, arr);

    // Minimize difference
    return min(take, notTake);
}

// top down - memoziation
// Intuition
// State: (index, currSum)
// Store min difference from this state
int solve(int index, int currSum, int totalSum,
          vector<int>& arr, vector<vector<int>>& dp) {

    // Base Case
    if (index < 0) {
        return abs(totalSum - 2 * currSum);
    }

    // If already computed
    if (dp[index][currSum] != -1) {
        return dp[index][currSum];
    }

    // Take
    int take = solve(index - 1, currSum + arr[index], totalSum, arr, dp);

    // Not take
    int notTake = solve(index - 1, currSum, totalSum, arr, dp);

    // Store minimum difference
    return dp[index][currSum] = min(take, notTake);
}

// bottom up - tabualation
int minSubsetSumDifference(vector<int>& arr, int n) {

    // Step 1: total sum
    int totalSum = 0;
    for (int x : arr) totalSum += x;

    int target = totalSum / 2;

    // Step 2: DP table only till target (half)
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Step 3: Base Case
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;  // sum 0 always possible
    }

    // First element
    if (arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    // Step 4: Fill DP
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {

            bool notTake = dp[i - 1][t];

            bool take = false;
            if (arr[i] <= t) {
                take = dp[i - 1][t - arr[i]];
            }

            dp[i][t] = take || notTake;
        }
    }

    // Step 5: Find best s1 (only from half)
    int mini = INT_MAX;

    for (int s1 = 0; s1 <= target; s1++) {
        if (dp[n - 1][s1]) {

            int diff = totalSum - 2 * s1;
            mini = min(mini, diff);
        }
    }

    return mini;
}

// intuition for this 
/*
We want to split array into 2 subsets such that their sums are as close as possible , to minimize the there difference 

Key Thought : 
Instead of thinking about 2 subsets, think only about:
Find one subset sum (s1)

Because:
s2 = totalSum - s1

Core Formula (REMEMBER THIS)

Difference:

|s1 - s2| = |totalSum - 2*s1|
So problem becomes:

Find a subset sum s1 as close as possible to totalSum / 2

How DP helps?

Use Subset Sum DP

dp[i][t] = can we make sum t

Final row gives:
all possible subset sums

Final Step
From all possible sums:

check only till totalSum / 2
pick best s1
*/