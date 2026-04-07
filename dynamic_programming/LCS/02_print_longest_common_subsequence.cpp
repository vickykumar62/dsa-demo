/* PRINT LCS (Recover the actual string)
Idea (1 line)

First build DP table → then trace back from dp[m][n]

Intuition (VERY IMPORTANT)
Case 1: Match
s1[i-1] == s2[j-1]

 This character is part of LCS
 Move diagonally ↖️

Case 2: Not Match

 Follow the path which gave max value

If dp[i-1][j] > dp[i][j-1] → go up ⬆️
Else → go left ⬅️

One-Line Memory Trick

“Match → take + go diagonal
Not match → move where value is bigger” */

class Solution {
public:
    string longestCommonSubsequence(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Step 1: Build DP
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Step 2: Backtrack
        string ans = "";
        int i = m, j = n;

        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

