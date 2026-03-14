class Solution {
public:
    int mySqrt(int x) {

        // Edge case: sqrt(0) = 0
        if(x == 0) return 0;

        int low = 1;
        int high = x;

        // store the best possible answer so far
        int ans = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // CASE 1: exact square root found
            if((long long)mid * mid == x)
                return mid;

            // CASE 2: mid^2 is too large
            // move to the left half
            else if((long long)mid * mid > x)
                high = mid - 1;

            // CASE 3: mid^2 is smaller than x
            // mid could be the answer, but we try to find a larger one
            else{
                ans = mid;
                low = mid + 1;
            }
        }

        // return the floor value of sqrt(x)
        return ans;
    }
};

// low  = minimum possible answer
// high = maximum possible answer