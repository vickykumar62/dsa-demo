class Solution {
public:

    // Recursive binary search to find the insert position
    void solve(int low, int high, int target, int &ans, vector<int>& nums){

        // Base case: search space exhausted
        if(low > high) return;

        // Find middle index
        int mid = low + (high - low) / 2;

        // If target is found, we can return immediately
        if(target == nums[mid]){
            ans = mid;
            return;
        }

        // If target is greater than middle element
        // search in the right half
        else if(target > nums[mid]){
            solve(mid + 1, high, target, ans, nums);
        }

        else{
            // nums[mid] > target
            // this position could be the insert position
            ans = mid;

            // But we check the left side to see
            // if there exists a smaller valid index
            solve(low, mid - 1, target, ans, nums);
        }
    }

    int searchInsert(vector<int>& nums, int target) {

        // Default answer = nums.size()
        // meaning insert at the end if all elements are smaller
        int ans = nums.size();

        solve(0, nums.size() - 1, target, ans, nums);

        return ans;
    }
};