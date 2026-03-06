class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        
        // Min Heap
        // pair structure:
        // { value , {row_index , column_index} }
        // Heap always gives the smallest value among all arrays
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        
        vector<int> ans;
        
        int n = mat.size();   // number of arrays
        
        // Step 1:
        // Push first element of every array into heap
        // Because each array is sorted, the smallest candidate
        // from each array is its first element
        for(int i = 0 ; i < n ; i++){
            pq.push({mat[i][0] , {i,0}});
        }
        
        
        // Step 2:
        // Process heap until empty
        while(!pq.empty()){
            
            // Extract smallest element among all arrays
            auto it = pq.top();
            pq.pop();
            
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // Add smallest element to answer
            ans.push_back(val);
            
            
            // Step 3:
            // After removing element from a row,
            // push the next element of the same row
            // (since that row is sorted)
            if(col + 1 < mat[row].size()){
                pq.push({mat[row][col+1] , {row , col+1}});
            }
        }
        
        return ans;
    }
};

Each array is already sorted.
So instead of inserting all elements into heap, we do something smarter.

push only : first element of each array

then : pop smallest , push next element from the same array

// this keep heap size small (k)
