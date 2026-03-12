class Solution {
public:

    // Recursive DFS function to generate numbers in lexicographical order
    void solve(vector<int>& ans,int curr,int n){

        // Base Case:
        // If the current number exceeds n, stop exploring this branch
        if(curr > n) return;

        // We don't add 0 because valid numbers start from 1
        if(curr > 0){
            ans.push_back(curr);
        }

        // If curr == 0 → first digit cannot be 0
        // So start from 1
        // Otherwise we can append digits from 0–9
        int start = (curr == 0) ? 1 : 0;

        // Try adding digits 0–9 to the current prefix
        for(int i = start ; i <= 9 ; i++){

            // Form the next number by appending digit i
            int next = curr * 10 + i;

            // If next number exceeds n, further digits will also exceed n
            // so we stop exploring this loop
            if(next > n) break;

            // Recursively explore numbers starting with this prefix
            solve(ans,next,n);
        }
    }

    vector<int> lexicalOrder(int n) {

        vector<int> ans;

        // Start recursion with prefix 0
        // From here we will generate 1..9 and then deeper numbers
        solve(ans,0,n);

        return ans;
    }
};

// for zero start the loop from 1 other wise fuction will calling it self and stack flow will happen
