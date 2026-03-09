class Solution {
public:
    
    // idx  -> starting index for recursion
    // curr -> current subsequence being built
    // ans  -> stores all valid subsequences
    void solve(int idx , int n , vector<int>& curr , vector<vector<int>>& ans , vector<int>& nums){
        
        // If subsequence length >= 2, it is valid
        if(curr.size() >= 2){
            ans.push_back(curr);
        }

        // Set to avoid duplicates at the same recursion level
        unordered_set<int> used;

        for(int i = idx ; i < n ; i++){

            // Skip duplicate numbers at the same recursion level
            if(used.count(nums[i])) 
                continue;

            // Ensure subsequence remains non-decreasing
            if(curr.empty() || curr.back() <= nums[i]){

                used.insert(nums[i]);     // mark number used at this level

                curr.push_back(nums[i]);  // choose element

                solve(i+1 , n , curr , ans , nums); // explore further

                curr.pop_back();          // backtrack
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0 , n , curr , ans , nums);

        return ans;
    }
};


// intuition  - This ensures that within the same recursion depth, the same value is chosen only once.
unordered_set<int> used;
for(int i = idx; i < n; i++){
    if(used.count(nums[i])) continue;
    used.insert(nums[i]);
}

At recursion level k, we are choosing the k-th element of the subsequence.
If the same value appears multiple times in the remaining array,
choosing it again at the same level would generate the same subsequences.

So we allow that value only once at that level.

Key Intuition
At level k:

I pick value x once.
I explore all subsequences starting with x at position k.
After backtracking, if I see another x, I skip it,
because those subsequences were already generated.


