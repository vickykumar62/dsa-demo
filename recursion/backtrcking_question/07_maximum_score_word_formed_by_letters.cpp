class Solution {
public:

    // Recursive backtracking function
    // idx        -> current word index we are deciding on
    // max_score  -> stores the maximum score found so far
    // curr_score -> score of the current chosen subset of words
    // freq       -> frequency of remaining letters available
    void solve(int idx , int &max_score , int curr_score , vector<int>& freq ,
               vector<string>& words , vector<int>& score ){

        // Update global maximum score with the current score
        max_score = max(max_score , curr_score);

        // If we have processed all words, stop recursion
        if(idx == words.size()) return;

        // Current word we are trying to include
        string s = words[idx];

        // Copy frequency array so we can modify it safely
        vector<int> tempFreq = freq;

        int temp_score = 0; // score gained if we take this word

        int i = 0;

        // Try to use letters of the current word
        while(i < s.length()){

            // Consume one character from available letters
            tempFreq[s[i] - 'a']--;

            // Add score of that character
            temp_score += score[s[i] - 'a'];

            // If letter frequency becomes negative,
            // we cannot form this word
            if(tempFreq[s[i] - 'a'] < 0) break;

            i++;
        }

        // If we successfully used all characters of the word
        if(i == s.length()){

            // Choose this word and recurse to next word
            solve(idx + 1 , max_score ,
                  curr_score + temp_score ,
                  tempFreq , words , score);
        }

        // Option 2: skip this word
        solve(idx + 1 , max_score ,
              curr_score ,
              freq , words , score);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        // Frequency array for available letters
        vector<int> freq(26 , 0);

        // Count available letters
        for(char &ch : letters){
            freq[ch - 'a']++;
        }

        int max_score = INT_MIN; // stores the best score
        int curr_score = 0;

        // Start recursion from first word
        solve(0 , max_score , curr_score , freq , words , score);

        return max_score;
    }
};