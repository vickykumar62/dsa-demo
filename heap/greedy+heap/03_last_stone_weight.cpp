class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // Max Heap -> always gives largest stone
        priority_queue<int> pq;
        
        // Insert all stones into heap
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        
        // Keep smashing while at least 2 stones exist
        while(pq.size() >= 2){
            
            // Step 1: Take two largest stones
            int y = pq.top();   // largest
            pq.pop();
            
            int x = pq.top();   // second largest
            pq.pop();
            
            // Step 2: Smash them
            if(x == y){
                // both destroyed → do nothing
                continue;
            }
            
            // If not equal, push remaining difference
            // Only the heavier one survives partially
            pq.push(y - x);
        }

        // If no stone left → return 0
        if(pq.empty()) return 0;
        
        // Otherwise, last remaining stone
        return pq.top();
    }
};
