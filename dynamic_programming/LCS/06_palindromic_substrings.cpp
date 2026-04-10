/* 📘 Palindromic Substring (Count All)
🧠 Core Idea (1 line)

“A string is palindrome if outer chars match AND inner substring is palindrome” */

// memoization
class Solution {
public:
    bool ispalindrome(int i, int j, string &s, vector<vector<int>> &dp){

        // Base case:
        // Single char or empty → always palindrome
        if(i >= j) return true;

        // Already computed
        if(dp[i][j] != -1) return dp[i][j];

        // If outer characters don't match → not palindrome
        if(s[i] != s[j]) return dp[i][j] = false;

        // If match → check inner substring
        return dp[i][j] = ispalindrome(i+1, j-1, s, dp);
    }

    int countSubstrings(string s) {
        
        int n = s.length();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Check all substrings
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                // If substring [i...j] is palindrome → count it
                if(ispalindrome(i, j, s, dp)) ans++;
            }
        }

        return ans;
    }
};

/* 🧠 Intuition (REVISION STYLE)
🔑 State

ispalindrome(i, j) = is substring from i to j palindrome?

🎯 Think Like This

“I am checking substring s[i...j]”

🔥 Rule (MOST IMPORTANT)
s[i] == s[j]  AND  inner is palindrome
🚫 Base Case
i >= j → true

💡 Memory:

“Single char or empty → always palindrome”

❌ Break Case
s[i] != s[j] → false
⚡ One-Line Memory Trick

“Match outside + palindrome inside” */

// tabulation
class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();

        // dp[i][j] = is substring i → j palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int ans = 0;

        // l = length of substring
        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){

                int j = i + l - 1;

                // Case 1: Single character
                if(i == j){
                    dp[i][j] = 1;
                }
                // Case 2: Two characters
                else if(j - i == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                // Case 3: Length >= 3
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                // Count if palindrome
                if(dp[i][j]) ans++;
            }
        }

        return ans;
    }
};

/* 🧠 Intuition (TABULATION — VERY IMPORTANT)
🔑 Why length loop?

“To compute dp[i][j], I need dp[i+1][j-1]”

👉 So smaller substrings must be solved first

🎯 Order
length = 1 → 2 → 3 → ...
🔥 Three Cases
1️⃣ Length = 1

Always palindrome

2️⃣ Length = 2

Just check both characters

3️⃣ Length ≥ 3
s[i] == s[j] && dp[i+1][j-1]
⚡ One-Line Memory Trick

“Outer match + inner palindrome”

🧠 Visualization
i → start
j → end

Shrink inward:
(i, j) → (i+1, j-1) */
