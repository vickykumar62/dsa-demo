class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        // CASE 1: If there is only one element
        // That element is automatically the peak
        if(nums.size() == 1) return 0;

        int n = nums.size();

        // CASE 2: Check if first element is a peak
        // first element only has one neighbour
        if(nums[0] > nums[1]) return 0;

        // CASE 3: Check if last element is a peak
        // last element only has one neighbour
        if(nums[n-1] > nums[n-2]) return n-1;

        // Now the peak must lie somewhere between index 1 and n-2
        int low = 1;
        int high = n - 2;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // CASE 4: mid itself is a peak
            // mid must be greater than both neighbours
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;

            // CASE 5: Increasing slope
            // nums[mid] < nums[mid+1]
            // Example: 1 2 3 4 5
            //                ↑
            // peak must exist on the right side
            else if(nums[mid] < nums[mid+1])
                low = mid + 1;

            // CASE 6: Decreasing slope
            // nums[mid] > nums[mid+1]
            // Example: 6 5 4 3
            //            ↑
            // peak must exist on the left side
            else if(nums[mid] > nums[mid+1])
                high = mid - 1;

            // Rare case when duplicates exist
            else
                low = mid + 1;
        }

        return -1; // normally this line is never reached
    }
};

// If we are moving UP (increasing slope)
// a peak must exist on the RIGHT side.

// If we are moving DOWN (decreasing slope)
// a peak must exist on the LEFT side.