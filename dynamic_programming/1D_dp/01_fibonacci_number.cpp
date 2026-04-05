/* Problem: Fibonacci Number
Each number is the sum of the previous two numbers
f(n) = f(n-1) + f(n-2) */

class Solution {
public:

    // Recursive function with memoization
    int solve(int n , vector<int> &dp){
        
        // Base case:
        // Fibonacci of 0 = 0, Fibonacci of 1 = 1
        if(n == 0 || n == 1) return n;

        // If already computed, return stored value
        // This avoids recomputation (DP optimization)
        if(dp[n] != -1) return dp[n];

        // Recurrence relation:
        // f(n) = f(n-1) + f(n-2)
        // Store result in dp before returning
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int fib(int n) {
        
        // DP array initialized with -1 (means not computed yet)
        vector<int> dp(31, -1);

        // Start recursion
        return solve(n, dp);
    }
};

/* Intuition 
Think:
“To compute n, I only need smaller subproblems (n-1, n-2)”
 Key Observations:
Overlapping subproblems:
fib(5) → calls fib(4) and fib(3)
fib(4) again calls fib(3) → repeated work
So we store results (memoization)*/

/* How to Think (IMPORTANT)
When you see a problem, ask:
Can I define answer in terms of smaller inputs?
Yes → f(n) = f(n-1) + f(n-2)
Are subproblems repeating?
Yes → use DP
What to store?
Store f(n) → dp[n]*/

// tabulation
int fib(int n) {
    if(n <= 1) return n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

