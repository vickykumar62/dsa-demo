class Solution {
public:
    int guessNumber(int n) {

        int low = 1;
        int high = n;

        while(low <= high){

            // Prevent overflow
            int mid = low + (high - low) / 2;

            int res = guess(mid);

            // Correct number found
            if(res == 0)
                return mid;

            // Picked number is higher
            else if(res == 1)
                low = mid + 1;

            // Picked number is lower
            else
                high = mid - 1;
        }

        return -1;
    }
};

// you have a guess function which tell whether the number you guess is equal to the number gussed
// computer or leeser or greater