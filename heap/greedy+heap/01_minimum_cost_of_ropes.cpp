class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        
        // If only one rope, no merging needed
        if(n == 1) return 0;
        
        int ans = 0;
        
        // Min Heap -> always gives smallest rope first
        // GREEDY IDEA:
        // We always merge the two smallest ropes
        priority_queue<int , vector<int> , greater<int> > pq;
        
        // Put all ropes into min heap
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        // Keep merging until only one rope remains
        while(pq.size() >= 2){
            
            // Step 1: Take two smallest ropes
            int first_min = pq.top();
            pq.pop();
            
            int second_min = pq.top();
            pq.pop();
            
            // Step 2: Merge them
            int merged = first_min + second_min;
            
            // WHY add to answer?
            // Because every merge operation costs sum of two ropes
            ans += merged;
            
            // Step 3: Push merged rope back
            // IMPORTANT:
            // This rope will be used again in future merges.
            // That is why we merge smallest first —
            // so the reusable rope is as small as possible.
            pq.push(merged);
        }
        
        // Final minimum total cost
        return ans;
    }
};

// Because every merged rope participates in future merges.
// So we minimize repeated cost by merging smallest ropes first.