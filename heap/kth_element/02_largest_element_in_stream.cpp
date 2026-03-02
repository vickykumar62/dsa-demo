class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;   // store k
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        int n = nums.size();
        
        // Step 1: Push first min(n, k) elements
        for(int i = 0; i < n && i < K; i++){
            pq.push(nums[i]);
        }
        
        // Step 2: Process remaining elements
        for(int i = K; i < n; i++){
            
            // If current element is bigger than
            // smallest among top K
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        
        // Case 1: Heap size less than K
        // Means we still don't have K elements
        if(pq.size() < K){
            pq.push(val);
        }
        else {
            // Case 2: Heap already has K elements
            // Replace only if val is bigger
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        
        // Top is always Kth largest
        return pq.top();
    }
};