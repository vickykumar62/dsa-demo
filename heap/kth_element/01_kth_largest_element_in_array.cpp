class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // Min Heap of size K
        // WHY Min Heap?
        // Because we want to keep K largest elements.
        // The smallest among those K will be the answer.
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Step 1: Insert first K elements
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        
        // Step 2: Traverse remaining elements
        for(int i = k; i < n; i++){
            
            // If current element is bigger than
            // smallest among top K elements
            if(nums[i] > pq.top()){
                
                // Remove smallest
                pq.pop();
                
                // Insert new bigger element
                pq.push(nums[i]);
            }
        }
        
        // After processing all elements:
        // Heap contains K largest elements.
        // Top element = Kth largest.
        return pq.top();
    }
};

// Kth largest → Min Heap
// Kth smallest → Max Heap
// time complexcity is n log(k)