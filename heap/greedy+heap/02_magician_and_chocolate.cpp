int nchoc(int A, int* B, int n2) {
    
    // Max Heap -> always gives largest bag
    priority_queue<int> pq;
    
    // Insert all bags into heap
    for(int i = 0; i < n2; i++){
        pq.push(B[i]);   // FIXED (B instead of b)
    }
    
    long long ans = 0;  // safer for large sum
    
    // We have A minutes (A chances)
    for(int i = 0; i < A; i++){
        
        // Step 1: Take bag with maximum chocolates
        int curr_max = pq.top();
        pq.pop();
        
        // Step 2: Add to answer (greedy gain)
        ans += curr_max;
        
        // Step 3: Bag refills to half
        // This bag may still be useful later
        pq.push(curr_max / 2);
        
        // GREEDY INTUITION:
        // Since we have limited A moves,
        // we always take maximum available chocolates now.
    }
    
    return ans;
}