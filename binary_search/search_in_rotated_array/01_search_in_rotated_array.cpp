class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // Target found
            if(nums[mid] == target)
                return mid;

            // Check if LEFT half is sorted
            if(nums[low] <= nums[mid]){

                // Target lies inside the sorted left half
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }

                else{
                    // Target must be in right half
                    low = mid + 1;
                }
            }

            // Otherwise RIGHT half must be sorted
            else{

                // Target lies inside sorted right half
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }

                else{
                    // Target must be in left half
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

// sorted array is rotated :

// Important observation:
// At least one half of the array is always sorted.

// So at every step:

// Find mid
// Check which half is sorted
// Check if target lies inside that sorted half
// Decide which half to eliminate