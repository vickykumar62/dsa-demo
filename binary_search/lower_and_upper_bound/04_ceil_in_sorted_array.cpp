class Solution {
  public:
    
    // Ceil = smallest element >= target
    int findCeil(vector<int>& nums, int target) {
        
        int low  = 0;
        int high = nums.size() - 1;
        
        // default: no ceil found
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            
            // nums[mid] could be the ceil
            if(nums[mid] >= target){
                ans = mid;
                
                // check left side for smaller valid element
                high = mid - 1;
            }
            else{
                // ceil must be on right side
                low = mid + 1;
            }
        }
        
        return ans;
    }
};