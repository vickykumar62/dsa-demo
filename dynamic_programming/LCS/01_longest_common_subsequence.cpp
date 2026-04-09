// recursion 
class Solution {
public:

    int solve(string &s1, string &s2, int m, int n){

        // Base case:
        // If any string becomes empty → no LCS
        if(m == 0 || n == 0) return 0;

        // If characters match
        if(s1[m-1] == s2[n-1]){
            // Take this character and move both back
            return 1 + solve(s1, s2, m-1, n-1);
        }

        // If not match
        // Try skipping from either string
        return max(
            solve(s1, s2, m-1, n),   // skip from s1
            solve(s1, s2, m, n-1)    // skip from s2
        );
    }

    int longestCommonSubsequence(string s1, string s2) {
        return solve(s1, s2, s1.length(), s2.length());
    }
};

/*  📘 LCS (Backward DP) — Revision Intuition
🧠 State (START HERE ALWAYS)

solve(m, n) = LCS of first m chars of s1 and first n chars of s2

👉 I am standing at end of both strings

🎯 Think Like This (VERY IMPORTANT)

“I am comparing last characters of both strings”

s1[m-1]  vs  s2[n-1]
🔥 Case 1: Characters Match

👉 Same character → must be part of LCS

1 + solve(m-1, n-1)

💡 Memory line:

“Match → take it and move both back”

❌ Case 2: Characters Don’t Match

👉 One of them is useless → remove one

max(
    solve(m-1, n),   // remove from s1
    solve(m, n-1)    // remove from s2
)

💡 Memory line:

“Mismatch → try removing both one by one”

🚫 Base Case
if(m == 0 || n == 0) return 0;

💡 Memory line:

“If one string is empty → no common subsequence”  */

// memoization
class Solution {
public:

    int solve(string &s1, string &s2, int m, int n, vector<vector<int>> &dp){

        // Base case
        if(m == 0 || n == 0) return 0;

        // Already computed
        if(dp[m][n] != -1) return dp[m][n];

        // Match
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = 1 + solve(s1, s2, m-1, n-1, dp);
        }

        // Not match
        return dp[m][n] = max(
            solve(s1, s2, m-1, n, dp),
            solve(s1, s2, m, n-1, dp)
        );
    }

    int longestCommonSubsequence(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        // dp[m][n] = LCS of first m and n characters
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(s1, s2, m, n, dp);
    }
};

// optimal 
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();

        // dp[i][j] = LCS of first i chars of s1 and first j chars of s2
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Base case:
        // dp[0][*] = 0 → empty string
        // dp[*][0] = 0

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                // Compare last characters of current prefix
                if(s1[i-1] == s2[j-1]){
                    // Match → take it + move diagonal
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Not match → remove one char
                    dp[i][j] = max(
                        dp[i-1][j],   // remove from s1
                        dp[i][j-1]    // remove from s2
                    );
                }
            }
        }

        return dp[m][n];
    }
};

/* 🧠 Intuition (REVISION STYLE — 30 sec recall)
🔑 Step 1: Meaning

dp[i][j] = answer for first i and j characters

👉 I am solving prefix vs prefix

🎯 Step 2: What am I doing?

“I am comparing last characters of both prefixes”

s1[i-1] vs s2[j-1]
🔥 Step 3: Decision
✅ Match

Same character → must be part of LCS

dp[i][j] = 1 + dp[i-1][j-1];

💡 Memory:

“Match → take + diagonal”

❌ Not Match

One is useless → remove one

dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

💡 Memory:

“Not match → remove one → take max”

🚫 Base Case

Empty string → LCS = 0

⚡ FULL THINKING IN 3 LINES

Compare last characters
Match → 1 + diagonal
Not match → max(up, left)

🧠 Visualization Trick
↖️ diagonal → match (take)
⬆️ up       → remove from s1
⬅️ left     → remove from s2
🎯 ONE-LINE FINAL MEMORY

“Match → diagonal + 1
Not match → max(up, left)”

🔥 Interview Insight

👉 Always say:

“dp[i][j] depends on previously solved smaller prefix problems” */