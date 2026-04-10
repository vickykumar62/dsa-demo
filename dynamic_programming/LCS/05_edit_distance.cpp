/* 📘 Edit Distance (Memo + Tabulation)
🧠 Core Idea (1 line)

“Convert word1 → word2 using minimum operations”

Allowed operations:
Insert
Delete
Replace */

// memoization
class Solution {
public:
    int solve(string &word1, string &word2, int m, int n, vector<vector<int>> &dp){

        // Base cases:

        // If word1 is empty → insert all characters of word2
        if(m == 0) return n;

        // If word2 is empty → delete all characters of word1
        if(n == 0) return m;

        // Already computed
        if(dp[m][n] != -1) return dp[m][n];

        // If last characters match
        if(word1[m-1] == word2[n-1]){
            // No operation needed → move both pointers
            return dp[m][n] = solve(word1, word2, m-1, n-1, dp);
        }
        else{
            // Try all 3 operations:

            // Insert → add character to word1 (match word2[n-1])
            int insert = 1 + solve(word1, word2, m, n-1, dp);

            // Delete → remove character from word1
            int del = 1 + solve(word1, word2, m-1, n, dp);

            // Replace → convert word1[m-1] to word2[n-1]
            int replace = 1 + solve(word1, word2, m-1, n-1, dp);

            return dp[m][n] = min({insert, del, replace});
        }
    }

    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(word1, word2, m, n, dp);
    }
};

/* 🧠 Intuition (REVISION STYLE — VERY IMPORTANT)
🔑 Step 1: State

solve(m, n) = minimum operations to convert
first m chars of word1 → first n chars of word2

🎯 Step 2: Think

“I am comparing last characters”

word1[m-1] vs word2[n-1]
✅ Case 1: Match

👉 Same character → no operation needed

solve(m-1, n-1)

💡 Memory:

“Same → ignore → move diagonal”

❌ Case 2: Not Match

👉 We must fix mismatch using 3 options:

1️⃣ Insert
1 + solve(m, n-1)

👉 Insert word2[n-1] into word1

💡 Memory:

“Insert → reduce target (n--)”

2️⃣ Delete
1 + solve(m-1, n)

👉 Remove character from word1

💡 Memory:

“Delete → reduce source (m--)”

3️⃣ Replace
1 + solve(m-1, n-1)

👉 Replace character

💡 Memory:

“Replace → move both”

🎯 Final Decision
min(insert, delete, replace)
⚡ One-Line Memory Trick

“Match → move diagonal
Not match → try insert, delete, replace → take min” */

// tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();

        // dp[i][j] = min operations to convert first i chars → first j chars
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){

                // Base cases
                if(i == 0){
                    dp[i][j] = j;  // insert all characters
                }
                else if(j == 0){
                    dp[i][j] = i;  // delete all characters
                }

                // If characters match
                else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({
                        dp[i][j-1],   // insert
                        dp[i-1][j],   // delete
                        dp[i-1][j-1]  // replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};

/* 🎯 FINAL 30-SEC MEMORY

Compare last characters
Same → move diagonal
Not same → try 3 ops:
insert (←), delete (↑), replace (↖️)
take minimum */