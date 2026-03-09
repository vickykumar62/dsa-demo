📖 The Story of Merge Sort

Goal:
Sort an array in ascending order.
Merge sort follows the Divide and Conquer idea:
Divide: Split the array into two halves.
Conquer: Recursively sort both halves.
Combine: Merge the two sorted halves into one sorted array.

🧩 The Three Parts of the Recursion Story

1️⃣ Base Case (The Ending)
When l >= r, it means the array has one or zero elements — it’s already sorted.
So, we stop.

2️⃣ Recursive Step (The Chapter Progression)
For any subarray with more than one element:
Find the middle index.
Recursively sort the left half.
Recursively sort the right half.
Then merge both halves.

3️⃣ Leap of Faith (The Trust)
We trust recursion to correctly sort both halves —
our job is only to merge those sorted halves properly.

🕒 Time Complexity: O(n log n)
💾 Space Complexity: O(n)

class Solution { 
public: 
    void merge(vector<int>& arr, int l, int mid, int r) { 
        int n1 = mid - l + 1; 
        int n2 = r - mid; 
        vector<int> left(n1), right(n2);

        for (int k = 0; k < n1; k++) 
            left[k] = arr[l + k]; 
        for (int k = 0; k < n2; k++) 
            right[k] = arr[mid + 1 + k]; 

        int i = l, k = 0, m = 0; 

        while (k < n1 && m < n2) { 
            if (left[k] <= right[m]) 
                arr[i++] = left[k++]; 
            else 
                arr[i++] = right[m++]; 
        } 

        while (k < n1) arr[i++] = left[k++]; 
        while (m < n2) arr[i++] = right[m++]; 
    } 

    void mergeSort(vector<int>& arr, int l, int r) { 
        if (l >= r) return;  // Base case
        int mid = l + ((r - l) >> 1); 
        mergeSort(arr, l, mid);      // Sort left half
        mergeSort(arr, mid + 1, r);  // Sort right half
        merge(arr, l, mid, r);       // Merge both halves
    } 
};