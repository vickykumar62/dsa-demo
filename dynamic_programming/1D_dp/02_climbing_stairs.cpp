/* Problem: Climbing Stairs
You can take 1 step or 2 steps at a time
Find number of distinct ways to reach step n */

/* Core Intuition (VERY IMPORTANT)
Think like this:
“To reach step n, where could I have come from?”
From n-1 (1 step jump)
From n-2 (2 step jump)
So total ways:
f(n) = f(n-1) + f(n-2) */

/* BRUTE FORCE (Recursion)
Intuition
Try all possibilities:
Take 1 step
Take 2 steps*/

class Solution {
public:

    int solve(int n){
        
        // If we go below 0 → invalid path
        if(n < 0) return 0;

        // If we reach exactly 0 → 1 valid way
        if(n == 0) return 1;

        // Choice 1: take 1 step
        int one_step = solve(n - 1);

        // Choice 2: take 2 steps
        int two_step = solve(n - 2);

        // Total ways = sum of both choices
        return one_step + two_step;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};

/* MEMOIZATION (Top-Down DP)
Intuition
“If I already know ways to reach n, don’t recompute it” */

class Solution {
public:

    int solve(int n , vector<int> &dp){

        // Invalid case
        if(n < 0) return 0;

        // Reached top → 1 way
        if(n == 0) return 1;

        // Already computed → reuse it
        if(dp[n] != -1) return dp[n];

        // Compute and store result
        int one_step = solve(n - 1, dp);
        int two_step = solve(n - 2, dp);

        return dp[n] = one_step + two_step;
    }

    int climbStairs(int n) {

        // dp[i] = number of ways to reach step i
        vector<int> dp(46, -1);

        return solve(n, dp);
    }
};

/* tabulation  
“Build answer from smaller values instead of recursion” 
 Instead of:
top → break into subproblems
We do:
start from base → build up to n
*/

class Solution {
public:
    int climbStairs(int n) {

        // Base cases:
        // 1 step → 1 way
        // 2 steps → 2 ways
        if(n <= 2) return n;

        // dp[i] = number of ways to reach step i
        vector<int> dp(n + 1, -1);

        // Initialize base values
        dp[1] = 1;
        dp[2] = 2;

        // Build solution from bottom (small → large)
        for(int i = 3; i <= n; i++){

            // Ways to reach i:
            // from (i-1) + from (i-2)
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Final answer
        return dp[n];
    }
};


