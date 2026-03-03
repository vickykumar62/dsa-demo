class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        
        // Step 1:
        // Flatten the 2D matrix into a 1D array
        // We ignore the sorted property of matrix here.
        vector<int> arr;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr.push_back(matrix[i][j]);
            }
        }
        
        // Step 2:
        // Sort the entire array
        // After sorting:
        // arr[0] -> smallest
        // arr[k-1] -> kth smallest
        sort(arr.begin(), arr.end());
        
        // Step 3:
        // Return kth smallest element
        return arr[k - 1];
    }
};

// better approach using the min heap

class Solution {
public:

    // Heapify function for MIN HEAP
    void heapify(int index, vector<int>& arr, int heapSize){
        
        int smallest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        // Compare with left child
        if(left < heapSize && arr[left] < arr[smallest])
            smallest = left;

        // Compare with right child
        if(right < heapSize && arr[right] < arr[smallest])
            smallest = right;

        // If root is not smallest, swap and recurse
        if(smallest != index){
            swap(arr[index], arr[smallest]);
            heapify(smallest, arr, heapSize);
        }
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // Step 1: Flatten matrix
        vector<int> arr;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr.push_back(matrix[i][j]);
            }
        }

        int heapSize = arr.size();

        // Step 2: Build Min Heap
        // Start from last non-leaf node
        for(int i = heapSize/2 - 1; i >= 0; i--){
            heapify(i, arr, heapSize);
        }

        // Step 3: Remove smallest (k-1) times
        for(int i = 0; i < k-1; i++){

            // Move current smallest to end
            swap(arr[0], arr[heapSize - 1]);

            // Reduce heap size
            heapSize--;

            // Restore heap property
            heapify(0, arr, heapSize);
        }

        // Now root is kth smallest
        return arr[0];
    }
};

Build heap → O(N)
Delete k times → O(k log N)

1. Converting matrix → array
2. Building a MIN HEAP
3. Removing smallest (k-1) times
4. Returning root

Memory Trigger for Build Heap
Start from last non-leaf  , Last non-leaf node: -> heapSize/2 - 1
Go backwards to 0
Call heapify
This ensures bottom-up correction.

Memory Trigger for Deleting Root
1. Swap root with last element
2. Reduce heap size
3. Heapify from index 0

