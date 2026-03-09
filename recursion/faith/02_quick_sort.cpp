 The Story of Quick Sort

Goal:
Sort an array efficiently by dividing it around a pivot element.
Quick Sort follows the Divide and Conquer idea:
Choose a Pivot: Pick one element (here, the last one).
Partition: Place the pivot in its correct sorted position —
all smaller elements go to its left, larger to its right.

Recursion:

Recursively sort the left part.
Recursively sort the right part.

🧩 The Three Parts of the Recursion Story
1. Base Case (The Ending)
If low >= high, it means the subarray has one or no elements — already sorted.
So, we stop.

2. Recursive Step (The Chapter Progression)
Choose a pivot.
Partition the array around the pivot.
Recursively sort the left and right sides.

3. Leap of Faith (The Trust)
We trust recursion to sort the smaller halves.
Our job is only to partition correctly.

 Complexity
Case	Description	Time Complexity
Best / Average	Pivot divides array evenly	O(n log n)
Worst	Pivot divides badly (already sorted array)	O(n²)

 Space Complexity: O(log n) — due to recursive call stack.

class Solution { 
public: 
    int partition(vector<int>& arr, int low, int high) { 
        int pivot_element = arr[high]; 
        int pivot_index = low; 

        for (int j = low; j < high; j++) { 
            if (arr[j] <= pivot_element) { 
                swap(arr[pivot_index], arr[j]); 
                pivot_index++; 
            } 
        } 

        swap(arr[pivot_index], arr[high]); 
        return pivot_index; 
    } 
    
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) { 
        if (low >= high) return;  // Base case

        int pivot_index = partition(arr, low, high);  // Place pivot correctly
        quickSort(arr, low, pivot_index - 1);         // Sort left part
        quickSort(arr, pivot_index + 1, high);        // Sort right part
    } 

    
};