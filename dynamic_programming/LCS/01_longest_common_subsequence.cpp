/* 1. Core Idea of LCS 
Problem:
Given two strings, find the length of the longest subsequence common in both.
Subsequence ≠ substring
You can skip characters, but order must remain. */

/* Golden Intuition (remember this forever)

“At every index, I have 2 choices:
match → take it
not match → try skipping from either string” */

class Solution {
public:
    int m , n;

    int solve(string s1 , string s2 , int i , int j , vector<vector<int>> &dp){

        // Base case:
        // If we reach end of any string → no subsequence possible
        if(i>=m || j>=n) return 0;

        // Already computed → reuse (DP optimization)
        if(dp[i][j] != -1) return dp[i][j];

        // If characters match
        // we take this character in LCS
        // move both pointers forward
        if(s1[i]==s2[j]) 
            return dp[i][j] = 1 + solve(s1,s2,i+1,j+1,dp);

        // If characters don't match
        // we have 2 choices:
        //    1. Skip s1[i]
        //    2. Skip s2[j]
        // take max of both possibilities
        return dp[i][j] = max(
            solve(s1,s2,i+1,j,dp),   // skip from s1
            solve(s1,s2,i,j+1,dp)    // skip from s2
        );
    }

    int longestCommonSubsequence(string s1, string s2) {

        m = s1.length();
        n = s2.length();

        // dp[i][j] = LCS from i → end and j → end
        vector<vector<int>> dp(1001 ,vector<int>(1001,-1));

        return solve(s1,s2,0,0,dp);
    }
};

// optimal 
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
    
        int m = s1.length();
        int n = s2.length();

        // dp[i][j] = LCS length of first i chars of s1 and first j chars of s2
        vector<vector<int>> dp(m+1,vector<int>(n+1, 0));

        // Base case already handled:
        // dp[0][*] = 0 → empty string
        // dp[*][0] = 0

        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                
                // If characters match
                if(s1[i-1]==s2[j-1]){
                    // Take this char → extend previous LCS
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Skip one character from either string
                    dp[i][j] = max(
                        dp[i-1][j],   // skip from s1
                        dp[i][j-1]    // skip from s2
                    );
                }
            }
        }

        return dp[m][n];
    }
};

/*  Why are we using i-1, j-1 in tabulation?

Let’s clear this intuitively (not formula).

 1. What does dp[i][j] actually mean?

 In tabulation:

dp[i][j] = LCS of first i characters of s1 and first j characters of s2 

2. Why do we look backward?

Because:

DP builds answers using smaller subproblems

 Case 1: Characters match
if(s1[i-1] == s2[j-1])
    dp[i][j] = 1 + dp[i-1][j-1];
 Intuition:
Current characters matched 
So include them in LCS (+1)
Now problem reduces to:

 “What was LCS before these characters?”

That is:

s1[0 ... i-2]
s2[0 ... j-2]

 Which is exactly dp[i-1][j-1]

 Think like this:

“I matched current char, now I want best answer before this match”

 Case 2: Characters don’t match
dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
 Intuition:

Mismatch → we cannot take both

So we try:

Skip current char of s1 → dp[i-1][j]
Skip current char of s2 → dp[i][j-1]
 Think like this:

“One of these characters is useless, let me try removing each one”  

 Why opposite directions?

Because:

Approach	Direction
Recursion	from start → end
Tabulation	from small → build up
 5. Golden Analogy

Think like climbing stairs:

Recursion: “Where can I go next?”
DP: “How did I reach here?” 

important ! 
“We use i-1, j-1 because dp[i][j] represents LCS of prefixes, so we refer to previously solved smaller prefix problems.”
One-Line Memory Trick

“Match → diagonal + 1
Not match → max(left, up)”   */