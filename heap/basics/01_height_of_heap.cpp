class Solution {
  public:
    int heapHeight(int n, int arr[]) { // here height is number of edges
        if(n==1) return 1;
        int height = floor(log2(n)) ;
        return height;
        
    }
};

// if height is number of node , than height = floor(log2(n)) + 1 ;
// 1. Heap = Complete Binary Tree.
// 2. Each level doubles nodes.
// 3. Height ≈ log₂(n).
