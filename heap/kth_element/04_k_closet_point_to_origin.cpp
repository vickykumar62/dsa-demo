// have to return all first k smallest distance form origin
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // Max Heap
        // Stores: {distance_squared, {x, y}}
        priority_queue<pair<int, pair<int,int>>> pq;
        
        int n = points.size();
        
        // Step 1: Insert first k points
        for(int i = 0; i < k; i++){
            int x = points[i][0];
            int y = points[i][1];
            
            // Use squared distance (no sqrt needed)
            int dist = x*x + y*y;
            
            pq.push({dist, {x, y}});
        }
        
        // Step 2: Process remaining points
        for(int i = k; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            
            // If current point is closer
            // than farthest among k closest
            if(dist < pq.top().first){
                
                pq.pop(); // remove farthest
                pq.push({dist, {x, y}});
            }
        }
        
        // Step 3: Extract all k elements
        vector<vector<int>> ans;
        
        while(!pq.empty()){
            ans.push_back({
                pq.top().second.first,
                pq.top().second.second
            });
            pq.pop();
        }
        
        return ans;
    }
};
