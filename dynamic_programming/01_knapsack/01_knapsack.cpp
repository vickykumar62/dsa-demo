/* 0/1 Knapsack – Core Idea 

You have items with weight and value

You have a bag capacity W

You can either:

Take item

Skip item

Goal: maximize value

 Pattern: Choice → Take / Not Take */

 1. Recursion (Brute Force)

Intuition
At each index:

If weight fits → 2 choices:
take
not take

Else → only skip 

int knapsack(int index, int W, vector<int>& wt, vector<int>& val) {
    // Base Case: no item left
    if (index == 0) {
        // If first item fits, take it
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    // Choice 1: NOT TAKE current item
    int notTake = knapsack(index - 1, W, wt, val);

    // Choice 2: TAKE current item (only if it fits)
    int take = INT_MIN;
    if (wt[index] <= W) {
        take = val[index] + knapsack(index - 1, W - wt[index], wt, val);
    }

    // Return max of both choices
    return max(take, notTake);
}


2. Memoization (Top-Down DP)

Intuition
Same recursion
Store results → avoid recomputation

int knapsack(int index, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // Base Case
    if (index == 0) {
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    // If already computed → return
    if (dp[index][W] != -1) return dp[index][W];

    int notTake = knapsack(index - 1, W, wt, val, dp);

    int take = INT_MIN;
    if (wt[index] <= W) {
        take = val[index] + knapsack(index - 1, W - wt[index], wt, val, dp);
    }

    // Store and return
    return dp[index][W] = max(take, notTake);
}

3. Tabulation (Bottom-Up)

Intuition
Build table dp[i][w]
Meaning: max value using first i items and capacity w

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base Case: first item
    for (int w = wt[0]; w <= W; w++) {
        dp[0][w] = val[0];  // if weight allows, take it
    }

    // Fill table
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {

            // Not take
            int notTake = dp[i - 1][w];

            // Take (if possible)
            int take = INT_MIN;
            if (wt[i] <= w) {
                take = val[i] + dp[i - 1][w - wt[i]];
            }

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}

do the dry run of this you will get it : 

Given
wt = [1, 2, 4]
val = [5, 4, 8]
W = 5
n = 3
