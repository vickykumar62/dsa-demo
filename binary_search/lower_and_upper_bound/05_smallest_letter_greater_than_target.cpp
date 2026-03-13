class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low = 0;
        int high = letters.size() - 1;

        // default answer = first letter (for wrap-around case)
        char ans = letters[0];

        while(low <= high){

            int mid = low + (high - low) / 2;

            // If current letter is greater than target
            // this could be the answer
            if(letters[mid] > target){
                ans = letters[mid];

                // search left to find smaller valid letter
                high = mid - 1;
            }

            else{
                // letters[mid] <= target
                // answer must be on right side
                low = mid + 1;
            }
        }

        return ans;
    }
};