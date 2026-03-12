class Solution {
public:

    // This function builds the nth row of the grammar
    string solve(int n){

        // Base Case:
        // The first row of the grammar is simply "0"
        if(n == 1) return "0";

        // Recursive Step:
        // Get the previous row
        string s = solve(n-1);

        string ans = "";

        // Build the current row based on grammar rules
        for(int i = 0 ; i < s.length() ; i++){

            // If previous symbol is '0'
            // it expands to "01"
            if(s[i] == '0'){
                ans.push_back('0');
                ans.push_back('1');
            }

            // If previous symbol is '1'
            // it expands to "10"
            else{
                ans.push_back('1');
                ans.push_back('0');
            }
        }

        return ans;
    }

    int kthGrammar(int n, int k) {

        // Build the full nth row
        string temp = solve(n);

        // Return the kth symbol (convert char to int)
        return temp[k-1] - '0';
    }
};

Intuition

Base Case - Row 1 = "0" 
This is the simplest case where we already know the answer.

Recursive Step - Each row is generated from the previous row using the rules:
So we:
Recursively build row(n-1)
Replace each character using the grammar rule.

Leap of Faith
When we write: string s = solve(n-1);

we trust recursion to correctly generate the previous row.
Then we simply expand each character to build the next row.
We do not worry about how row(n-1) was built, we only focus on transforming it.

// optimal

class Solution {
public:
    int kthGrammar(int n, int k) {

        // Base Case:
        // The first row has only one element "0"
        // So the answer must be 0.
        if(n == 1 && k == 1) return 0;

        // Length of the current row
        // Row n has length = 2^(n-1)
        long long length = pow(2 , n-1);

        // Middle point of the row
        int mid = length / 2;

        // Case 1: If k lies in the first half
        // The first half of row n is exactly the same as row (n-1)
        // So we recursively find the kth element in the previous row
        if(k <= mid){
            return kthGrammar(n-1 , k);
        }

        // Case 2: If k lies in the second half
        // The second half is the flipped version of the first half
        // So we map it back to the corresponding position
        // in the first half and flip the result
        return !kthGrammar(n-1 , k - mid);
    }
};

n = 1 → 0
n = 2 → 01
n = 3 → 0110
n = 4 → 01101001

notice the pattern - row(n) = row(n-1) + flipped(row(n-1))

So the row is always made of two halves: 
first half  = previous row
second half = flipped previous row



Logic Behind the Recursive Solution

Since the row has two halves:

Case 1 — k is in the first half
k ≤ mid

The first half is exactly the same as row(n-1).

So the answer is:

kthGrammar(n-1, k)
Case 2 — k is in the second half
k > mid

The second half is the flipped version of the first half.

So we:

Map the position back to the first half

k - mid

Flip the result

!kthGrammar(n-1, k-mid)

Each row is previous row + flipped previous row, so locate k in the correct half and recursively trace it back.

