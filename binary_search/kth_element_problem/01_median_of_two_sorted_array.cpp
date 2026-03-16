class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;  // pointers for both arrays

        // median positions in merged array
        int index1 = (n + m) / 2 - 1;
        int index2 = (n + m) / 2;

        int ele1 = -1, ele2 = -1;

        int count = 0; // index of merged array

        // merge both arrays until we reach index2
        while(i < n && j < m && count <= index2){

            int curr;

            // choose smaller element (merge step)
            if(nums1[i] < nums2[j]){
                curr = nums1[i++];
            }
            else{
                curr = nums2[j++];
            }

            // store median elements
            if(count == index1) ele1 = curr;
            if(count == index2) ele2 = curr;

            count++;
        }

        // remaining elements of nums1
        while(i < n && count <= index2){

            int curr = nums1[i++];

            if(count == index1) ele1 = curr;
            if(count == index2) ele2 = curr;

            count++;
        }

        // remaining elements of nums2
        while(j < m && count <= index2){

            int curr = nums2[j++];

            if(count == index1) ele1 = curr;
            if(count == index2) ele2 = curr;

            count++;
        }

        // if total length is odd
        if((n + m) % 2 == 1)
            return ele2;

        // if even
        return (ele1 + ele2) / 2.0;
    }
};

// optimal approach 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        /*
        Always perform binary search on the smaller array.
        This ensures the complexity remains O(log(min(n,m))).
        */
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;

        /*
        Total elements needed in the left half after partition.
        +1 ensures correct handling of odd total length.
        */
        int left_size = (n1 + n2 + 1) / 2;

        while(low <= high){

            /*
            mid1 = number of elements taken from nums1
            mid2 = remaining elements taken from nums2
            */
            int mid1 = low + (high - low) / 2;
            int mid2 = left_size - mid1;

            /*
            l1 = last element of left part of nums1
            l2 = last element of left part of nums2
            r1 = first element of right part of nums1
            r2 = first element of right part of nums2

            If partition is at the boundary, use INT_MIN / INT_MAX
            to simplify comparisons.
            */
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1 > 0) l1 = nums1[mid1-1];
            if(mid2 > 0) l2 = nums2[mid2-1];

            /*
            Check if partition is correct.

            Correct partition means:
            max(left side) <= min(right side)

            i.e.
            l1 <= r2 AND l2 <= r1
            */
            if(l1 <= r2 && l2 <= r1){

                /*
                If total length is odd,
                median is the maximum element on the left side.
                */
                if((n1 + n2) % 2 == 1)
                    return max(l1, l2);

                /*
                If total length is even,
                median is average of middle two elements.
                */
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            }

            /*
            If l1 > r2
            means we took too many elements from nums1
            so move partition left.
            */
            else if(l1 > r2){
                high = mid1 - 1;
            }

            /*
            If l2 > r1
            means we took too few elements from nums1
            so move partition right.
            */
            else{
                low = mid1 + 1;
            }
        }

        return 0; // should never reach here
    }
};