class Solution {
public:

    // Function to calculate total hours needed
    // if Koko eats at speed = mid bananas/hour
    long long solve(vector<int>& piles, int mid){

        long long hours = 0;

        for(int &num : piles){

            // Time needed for one pile
            // ceil(num / mid)
            // We convert to double to avoid integer division
            hours += ceil((double)num / mid);
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Find maximum pile
        // This will be the maximum possible eating speed
        int max_ele = INT_MIN;

        for(int &num : piles){
            max_ele = max(max_ele, num);
        }

        // Binary search range
        int low = 1;           // minimum possible speed
        int high = max_ele;    // maximum possible speed

        int ans = max_ele;

        while(low <= high){

            // middle speed we want to test
            int mid = low + (high - low) / 2;

            // calculate hours needed at this speed
            long long hour = solve(piles, mid);

            // If hours exceed allowed time
            // speed is too slow → increase speed
            if(hour > h){
                low = mid + 1;
            }

            // Speed works
            // Try to minimize the speed
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        // minimum valid speed
        return ans;
    }
};