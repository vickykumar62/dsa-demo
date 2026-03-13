class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        // store the minimum value found so far
        int ans = INT_MAX;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // Check if mid itself is the pivot (minimum element)
            // The minimum element will be smaller than both neighbours
            if(mid != 0 && mid != nums.size()-1 &&
               nums[mid] < nums[mid-1] &&
               nums[mid] < nums[mid+1])
                return nums[mid];

            // If left half is sorted
            if(nums[low] < nums[mid]){

                // since left half is sorted, nums[low] is the smallest in that half
                ans = min(ans, nums[low]);

                // minimum must be in right half
                low = mid + 1;
            }

            else{

                // right half is sorted OR pivot lies in left half
                // so nums[mid] could be a candidate for minimum
                ans = min(ans, nums[mid]);

                // search in left half
                high = mid - 1;
            }
        }

        return ans;
    }
};

// left half is sorted , here the minimim is num[low]
// right half is sorted , here the minimum is num[high]