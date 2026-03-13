class Solution{
public:

    // Lower Bound = first index where nums[index] >= target
    // If all elements are smaller than target, return nums.size()

    int lower_bound(vector<int>& nums, int target){

        int low = 0;
        int high = nums.size() - 1;

        // default answer: insert at end
        int ans = nums.size();

        while(low <= high){

            int mid = low + (high - low) / 2;

            // If nums[mid] >= target
            // this position could be the lower bound
            if(nums[mid] >= target){
                ans = mid;

                // search left to find smaller valid index
                high = mid - 1;
            }

            else{
                // nums[mid] < target
                // lower bound must be on the right side
                low = mid + 1;
            }
        }

        return ans;
    }
};