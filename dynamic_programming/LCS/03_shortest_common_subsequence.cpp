// recursion + memoziaton
class Solution {
public:
    int solve(string &str1, string &str2, int m, int n, vector<vector<int>> &dp){

        // Base case:
        // If both strings are empty
        if(m == 0 && n == 0) return 0;

        // If str1 is empty → we must take all characters of str2
        if(m == 0) return n;

        // If str2 is empty → we must take all characters of str1
        if(n == 0) return m;

        // Already computed
        if(dp[m][n] != -1) return dp[m][n];

        // If characters match
        if(str1[m-1] == str2[n-1]){
            // Take this character once
            // Move both pointers
            return dp[m][n] = 1 + solve(str1, str2, m-1, n-1, dp);
        }
        else{
            // Characters don't match
            // Two choices:

            // 1. Take character from str1
            // 2. Take character from str2

            return dp[m][n] = 1 + min(
                solve(str1, str2, m-1, n, dp),   // take from str1
                solve(str1, str2, m, n-1, dp)    // take from str2
            );
        }
    }

    int minSuperSeq(string &str1, string &str2) {
        
        int m = str1.length();
        int n = str2.length();

        // dp[m][n] = SCS length for first m and n characters
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(str1, str2, m, n, dp);
    }
};

/* 🧠 Intuition Notes (for Revision)
🔑 State Definition

solve(m, n) = SCS length of first m chars of str1 and first n chars of str2

🔥 Base Cases
Case	Meaning
m == 0	take all of str2
n == 0	take all of str1
✅ Match Case
str1[m-1] == str2[n-1]

👉 Add once
👉 Move both

“Same character → no duplication needed”

❌ Not Match Case

👉 Must include one character

1 + min(
    solve(m-1, n),
    solve(m, n-1)
)

“Try both insertions → pick minimum length”

🎯 One-Line Memory Trick

“Match → 1 + diagonal
Not match → 1 + min(up, left)”  */

// tabulation 
class Solution {
public:
    int minSuperSeq(string &str1, string &str2) {
        
        int m = str1.length();
        int n = str2.length();

        // dp[i][j] = length of SCS for first i chars of str1 and first j chars of str2
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Base cases:
        // If one string is empty → we must take all characters of the other
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;  // take all from str1
        }

        for(int j = 0; j <= n; j++){
            dp[0][j] = j;  // take all from str2
        }

        // Fill DP table
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                // If characters match
                if(str1[i-1] == str2[j-1]){
                    // Take this character once
                    // Move diagonally (both strings consumed)
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Characters don't match
                    // We have 2 choices:
                    
                    // 1. Take char from str1 → move i-1
                    // 2. Take char from str2 → move j-1
                    
                    dp[i][j] = 1 + min(
                        dp[i-1][j],   // insert str1[i-1]
                        dp[i][j-1]    // insert str2[j-1]
                    );
                }
            }
        }

        return dp[m][n];
    }
};

/* 🧠 Intuition Breakdown (SUPER IMPORTANT)
✅ Case 1: Characters match
str1[i-1] == str2[j-1]

👉 Only add it once
👉 Move both pointers

“Same character → no need to duplicate”

❌ Case 2: Characters don’t match

👉 We must include one of them

Two options:
Take from str1
Take from str2

👉 Add +1 because we are inserting a character

👉 Take minimum

🎯 Visualization Thinking

At (i, j):

↖️ diagonal → match (best case)
⬆️ → take from str1
⬅️ → take from str2
⚡ One-Line Memory Trick

“Match → take once (diagonal)
Not match → 1 + min(up, left)” */

/* 🔄 Compare with LCS (VERY IMPORTANT)
LCS	SCS
maximize length	minimize length
match → +1	match → +1
not match → max	not match → min

🔥 Even Better (INTERVIEW GOLD)

👉 You can also say:

SCS = m + n - LCS 

So:

return m + n - lcs(str1, str2);*/