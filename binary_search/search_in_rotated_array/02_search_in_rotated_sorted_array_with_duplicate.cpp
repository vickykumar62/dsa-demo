class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // If middle element is the target, return true
            if(nums[mid] == target)
                return true;

            // If duplicates exist at both ends, we cannot determine
            // which half is sorted. So shrink the search space.
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            // Check if the LEFT half is sorted
            if(nums[low] <= nums[mid]){

                // If target lies inside the sorted left half
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    // Otherwise search in the right half
                    low = mid + 1;
                }
            }

            // Otherwise the RIGHT half must be sorted
            else{

                // If target lies inside the sorted right half
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    // Otherwise search in the left half
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};