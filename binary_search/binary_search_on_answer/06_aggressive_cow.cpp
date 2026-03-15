class Solution {
  public:
  
    // Check if we can place k cows
    // such that minimum distance between cows is at least 'mid'
    bool solve(vector<int> &stalls , int k , int mid){
        
        int n = stalls.size();
        
        // place the first cow in the first stall
        int last_position = stalls[0];
        
        k--;  // one cow already placed
        
        for(int i = 1 ; i < n ; i++){
            
            // if current stall is far enough from last placed cow
            if(stalls[i] - last_position >= mid){
                
                // place cow here
                last_position = stalls[i];
                k--;
            }
            
            // all cows placed successfully
            if(k == 0) return true;
        }
        
        // not enough stalls to place all cows
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        
        // sort stall positions
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        
        // minimum possible distance
        int low = 1;
        
        // maximum possible distance
        int high = stalls[n-1];
        
        int ans = 0;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            
            // check if we can maintain distance 'mid'
            if(solve(stalls, k, mid)){
                
                ans = mid;       // valid answer
                
                // try to maximize the minimum distance
                low = mid + 1;
            }
            else{
                
                // distance too large, reduce it
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

// key observation : If we try a distance d

// If we CAN place all cows with distance ≥ d
// → smaller distances will also work

// If we cannot place cows with distance d:
// → larger distances will also fail

// This gives a monotonic search space, which allows Binary Search.

