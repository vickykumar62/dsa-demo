class Solution {
public:

    // This function calculates how many days are required
    // if the ship capacity is fixed at 'capacity'
    int solve(vector<int>& weights, int capacity){

        int count_days = 1;   // we start shipping on day 1
        int curr_weight = 0;  // current weight loaded on the ship for the day

        for(int &w : weights){

            // If adding this package exceeds the ship capacity,
            // we must ship the current packages and start a new day
            if(curr_weight + w > capacity){
                count_days++;      // move to next day
                curr_weight = 0;   // reset weight for new day
            }

            // load the package on the ship
            curr_weight += w;
        }

        // return total number of days required with this capacity
        return count_days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum capacity must be at least the heaviest package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum capacity = sum of all packages
        // meaning we ship everything in one day
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;  // store the minimum valid capacity

        while(low <= high){

            // mid represents a possible ship capacity
            int mid = low + (high - low) / 2;

            // calculate how many days are needed with this capacity
            int required_days = solve(weights, mid);

            // If more days are needed than allowed
            // the capacity is too small → increase capacity
            if(required_days > days){
                low = mid + 1;
            }

            // Capacity works → try to find a smaller valid capacity
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        // return the minimum capacity that allows shipping within 'days'
        return ans;
    }
};