class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        // Max Heap -> always gives richest pile
        priority_queue<int> pq;
        
        // Insert all piles
        for(int i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }

        // Perform operation k times
        for(int i = 0; i < k; i++){   // FIXED condition
            
            // Step 1: Take richest pile
            int largest = pq.top();
            pq.pop();
            
            // Step 2: Replace with floor(sqrt(largest))
            int remaining = floor(sqrt(largest));
            
            // Step 3: Push updated pile back
            pq.push(remaining);
        }

        // Sum remaining gifts
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        // Max Heap -> always gives richest pile
        priority_queue<int> pq;
        
        // Insert all piles
        for(int i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }

        // Perform operation k times
        for(int i = 0; i < k; i++){   // FIXED condition
            
            // Step 1: Take richest pile
            int largest = pq.top();
            pq.pop();
            
            // Step 2: Replace with floor(sqrt(largest))
            int remaining = floor(sqrt(largest));
            
            // Step 3: Push updated pile back
            pq.push(remaining);
        }

        // Sum remaining gifts
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};