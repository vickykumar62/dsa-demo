class Solution {
public:

    // Recursive binary search function
    int solve(int low, int high, int target, vector<int>& nums) {

        // Base case: if search space becomes invalid
        // means the element is not present
        if (low > high) return -1;

        // Find middle index of current search space
        int mid = low + (high - low ) / 2;

        // If middle element is the target
        // return its index
        if (nums[mid] == target) return mid;

        // If target is smaller than middle element
        // search in the left half
        if (target < nums[mid])
            return solve(low, mid - 1, target, nums);

        // If target is greater than middle element
        // search in the right half
        else
            return solve(mid + 1, high, target, nums);
    }

    int search(vector<int>& nums, int target) {

        // Start binary search from index 0 to n-1
        return solve(0, nums.size() - 1, target, nums);
    }
};