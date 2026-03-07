class Solution {
public:

    void solve(int idx , int curr_sum , int target ,
               vector<int>& nums , int &ans){

        // Base case:
        // If we processed all numbers
        if(idx == nums.size()){

            // check if expression equals target
            if(curr_sum == target)
                ans++;

            return;
        }

        // Choice 1: put '+' before nums[idx]
        solve(idx+1 , curr_sum + nums[idx] , target , nums , ans);

        // Choice 2: put '-' before nums[idx]
        solve(idx+1 , curr_sum - nums[idx] , target , nums , ans);
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int ans = 0;

        solve(0 , 0 , target , nums , ans);

        return ans;
    }
};
