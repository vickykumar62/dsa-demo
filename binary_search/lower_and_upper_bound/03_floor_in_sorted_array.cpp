class Solution {
  public:

    // Floor = largest element <= target
    int findFloor(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        // Default = -1 (means no floor exists)
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // If element is greater than target
            // floor must be on the left side
            if (nums[mid] > target) {
                high = mid - 1;
            }

            else {
                // nums[mid] <= target
                // this could be the floor
                ans = mid;

                // but check right side for larger valid element
                low = mid + 1;
            }
        }

        return ans;
    }
};