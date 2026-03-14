class Solution {
public:

    // Calculate the sum of ceil(nums[i] / divisor)
    int solve(vector<int>& nums, int divisor){

        int sum = 0;

        for(int &num : nums){

            // ceil(num / divisor)
            // converting to double to avoid integer division
            sum += ceil((double)num / divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        // smallest possible divisor
        int low = 1;

        // largest possible divisor
        int high = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while(low <= high){

            // candidate divisor
            int mid = low + (high - low) / 2;

            // calculate sum with this divisor
            int sum = solve(nums, mid);

            // sum exceeds threshold
            // divisor is too small → increase divisor
            if(sum > threshold){
                low = mid + 1;
            }

            // divisor works
            // try to minimize divisor
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};