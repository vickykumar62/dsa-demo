class Solution{
public :

    // Upper Bound = first index where nums[index] > target
    // If no such element exists, return nums.size()

    int upper_bound(vector<int>& nums , int target){

        int low = 0;
        int high = nums.size() - 1;

        // default answer → after last element
        int ans = nums.size();

        while(low <= high){

            int mid = low + (high - low) / 2;

            // If nums[mid] > target
            // this could be the answer
            if(nums[mid] > target){
                ans = mid;

                // check left side for smaller valid index
                high = mid - 1;
            }

            else{
                // nums[mid] <= target
                // upper bound must be on right side
                low = mid + 1;
            }
        }

        return ans;
    }
};