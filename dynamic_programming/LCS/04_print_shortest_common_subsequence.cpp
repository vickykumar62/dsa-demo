// optimal
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();

        // dp[i][j] = length of SCS of first i and j characters
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        // Base case:
        // If one string is empty → take all of the other
        for(int j = 0 ; j <= n ; j++){
            dp[0][j] = j;
        }

        for(int i = 0 ; i <= m ; i++){
            dp[i][0] = i;
        }

        // Build DP table
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){

                if(s1[i-1] == s2[j-1]){
                    // Match → take once
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Not match → insert one character
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Backtracking to build string
        string ans = "";
        int i = m, j = n;

        while(i > 0 && j > 0){

            // Match → take once and move diagonal
            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]);
                i--; j--;
            }
            else{
                // Choose smaller path
                if(dp[i-1][j] < dp[i][j-1]){
                    ans.push_back(s1[i-1]); // take from s1
                    i--;
                }
                else{
                    ans.push_back(s2[j-1]); // take from s2
                    j--;
                }
            }
        }

        // Add remaining characters
        while(i > 0){
            ans.push_back(s1[i-1]);
            i--;
        }

        while(j > 0){
            ans.push_back(s2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* ;
🧠 Intuition (REVISION STYLE — VERY IMPORTANT)
🔑 Step 1: What am I doing?

“I want to merge both strings with minimum duplication”

🎯 Step 2: Think at (i, j)

“I am comparing last characters”

s1[i-1] vs s2[j-1]
🔥 Case 1: Match

👉 Same character → include only once

💡 Memory:

“Same → don’t duplicate → go diagonal”

❌ Case 2: Not Match

👉 We must include one character

👉 Choose the path with smaller SCS length

💡 Memory:

“Not match → pick smaller path → include that char”

🔁 Backtracking Logic (MOST IMPORTANT)
✅ Match
↖️ take once
❌ Not Match
If dp[i-1][j] < dp[i][j-1]
take from s1 (go up ⬆️)
Else
take from s2 (go left ⬅️)
⚡ One-Line Memory Trick

“Match → take once + diagonal
Not match → take from smaller side”

🧠 Visualization
↖️ = match (take once)
⬆️ = take from s1
⬅️ = take from s2 */