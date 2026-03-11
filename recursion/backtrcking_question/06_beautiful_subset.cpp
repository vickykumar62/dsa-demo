class Solution {
public:

    // Backtracking function
    void solve(int idx , int k , int &ans ,
               unordered_map<int,int>& mpp ,
               vector<int>& nums){

        if(idx == nums.size()) return;

        for(int i = idx ; i < nums.size() ; i++){

            // Check if adding nums[i] violates beautiful condition
            // i.e., no element with difference k already exists
            if(mpp[nums[i]-k] == 0 && mpp[nums[i]+k] == 0){

                // Choose element
                mpp[nums[i]]++;

                // Count this subset
                ans++;

                // Explore further elements
                solve(i+1 , k , ans , mpp , nums);

                // Backtrack
                mpp[nums[i]]--;
            }
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;  // frequency map
        int ans = 0;

        solve(0 , k , ans , mpp , nums);

        return ans;
    }
};

Intuition

We build subsets using backtracking.
While building a subset, we must ensure that no two elements have absolute difference k.
So before adding a number x into the current subset, we check:

(x - k) is not already in the subset
(x + k) is not already in the subset

If both are absent, adding x will not create a pair with difference k, so it is safe to include.
To efficiently check this, we maintain a frequency map (mpp) of elements currently present in the subset.

Backtracking Idea

At every step:
Try picking an element.
Check if it violates the beautiful condition.
If valid:
add it to the subset
count this subset
explore further elements
After recursion, remove it (backtrack) to try other possibilities.