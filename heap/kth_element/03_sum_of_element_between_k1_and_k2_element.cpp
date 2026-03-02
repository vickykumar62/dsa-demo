class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        
        // -----------------------------------------
        // STEP 1: Get sum of first K1 smallest elements
        // Using Max Heap (to keep K smallest)
        // -----------------------------------------
        
        priority_queue<long long> pq1;  // Max Heap
        long long temp1 = 0;            // Sum of K1 smallest
        
        // Insert first K1 elements
        for(int i = 0; i < K1; i++){
            pq1.push(A[i]);
            temp1 += A[i];
        }
        
        // Process remaining elements
        for(int i = K1; i < N; i++){
            
            // If current element is smaller than
            // largest among K1 smallest
            if(A[i] < pq1.top()){
                
                // Remove largest among K1 smallest
                temp1 -= pq1.top();
                pq1.pop();
                
                // Insert smaller element
                pq1.push(A[i]);
                temp1 += A[i];
            }
        }
        
        
        // -----------------------------------------
        // STEP 2: Get sum of first K2 smallest elements
        // -----------------------------------------
        
        priority_queue<long long> pq2;  // Max Heap
        long long temp2 = 0;            // Sum of K2 smallest
        
        for(int i = 0; i < K2; i++){
            pq2.push(A[i]);
            temp2 += A[i];
        }
        
        for(int i = K2; i < N; i++){
            
            if(A[i] < pq2.top()){
                
                temp2 -= pq2.top();
                pq2.pop();
                
                pq2.push(A[i]);
                temp2 += A[i];
            }
        }
        
        // Remove K2-th smallest itself
        // Because we want strictly between
        temp2 -= pq2.top();
        
        // Final Answer:
        // (sum of first K2-1 smallest)
        // minus
        // (sum of first K1 smallest)
        return temp2 - temp1;
    }
};