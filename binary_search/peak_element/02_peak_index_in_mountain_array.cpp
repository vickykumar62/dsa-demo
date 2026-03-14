class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // Peak cannot be at index 0 or n-1 in a mountain array
        // because the array must first increase and then decrease
        int low = 1;
        int high = arr.size() - 2;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // CASE 1: mid is the peak
            // it must be greater than both neighbours
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;

            // CASE 2: increasing slope
            // Example: 1 3 5 7 9
            //                ↑
            // peak must lie on the right side
            else if(arr[mid] < arr[mid+1])
                low = mid + 1;

            // CASE 3: decreasing slope
            // Example: 9 7 6 5 4
            //          ↑
            // peak must lie on the left side
            else
                high = mid - 1;
        }

        return -1; // normally never reached
    }
};