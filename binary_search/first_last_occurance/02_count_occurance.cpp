class Solution {
  public:
      // Function to find FIRST occurrence of target
    int solve1(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                // Target found, but we check LEFT side
                // because there might be an earlier occurrence
                ans = mid;
                high = mid - 1;
            }

            else if (target > nums[mid]) {

                // Target must be on the RIGHT side
                low = mid + 1;
            }

            else {

                // Target must be on the LEFT side
                high = mid - 1;
            }
        }

        return ans;
    }


    // Function to find LAST occurrence of target
    int solve2(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                // Target found, but we check RIGHT side
                // because there might be a later occurrence
                ans = mid;
                low = mid + 1;
            }

            else if (target > nums[mid]) {

                // Target must be on RIGHT side
                low = mid + 1;
            }

            else {

                // Target must be on LEFT side
                high = mid - 1;
            }
        }

        return ans;
    }
    int countFreq(vector<int>& nums, int target) {
        
        int first_occurrence = solve1(nums, target);
        int last_occurrence = solve2(nums, target);
        
        if(first_occurrence==-1) return 0;
        
        return last_occurrence - first_occurrence + 1;
        
    }
};
