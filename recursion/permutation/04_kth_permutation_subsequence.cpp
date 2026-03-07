class Solution {
public:

    string ans;   // stores the k-th permutation as a string

    // Recursive function to generate permutations
    void solve(int len , int num , int &count , vector<bool>& visited , int n , int k){

        // If we already found the k-th permutation, stop recursion
        if(count >= k) return;

        // Base Case:
        // If the current permutation length becomes n
        // it means we formed a complete permutation
        if(len == n){

            count++;   // one permutation is generated

            // If this is the k-th permutation, store it
            if(count == k){
                ans = to_string(num);
            }

            return;
        }

        // Try placing numbers from 1 to n
        for(int i = 1 ; i <= n ; i++){

            // If this number is already used in the current permutation, skip it
            if(visited[i]) continue;

            // Choose the number
            visited[i] = true;

            // Add digit to the number being formed
            // Example: num = 12 , i = 3 → new number = 123
            solve(len + 1 , num * 10 + i , count , visited , n , k);

            // Backtrack: remove the number so we can try another choice
            visited[i] = false;
        }
    }

    string getPermutation(int n, int k) {

        int num = 0;     // number formed during permutation building
        int count = 0;   // counts how many permutations we generated

        // visited[i] tells whether number i is already used
        vector<bool> visited(n+1,false);

        // start recursion
        solve(0 , num , count , visited , n , k);

        return ans;
    }
};