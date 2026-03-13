class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        // Store the minimum value found so far
        int ans = INT_MAX;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // Check if mid itself is the pivot (minimum element)
            // Pivot is smaller than both its neighbours
            if(mid != 0 && mid != nums.size()-1 &&
               nums[mid] < nums[mid-1] &&
               nums[mid] < nums[mid+1])
                return nums[mid];

            // If duplicates exist at both ends, we cannot decide
            // which half is sorted, so shrink the search space
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                ans = min(ans, nums[mid]);
                low++;     // remove duplicate from left
                high--;    // remove duplicate from right
                continue;
            }

            // If left half is sorted
            else if(nums[low] <= nums[mid]){

                // nums[low] is the smallest element in this sorted half
                ans = min(ans, nums[low]);

                // Minimum must lie in the right half
                low = mid + 1;
            }

            else{

                // Pivot lies in the left half
                // nums[mid] could be a candidate for minimum
                ans = min(ans, nums[mid]);

                // Search left side
                high = mid - 1;
            }
        }

        return ans;
    }
};