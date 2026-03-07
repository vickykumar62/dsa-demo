class Solution {
public:

    void solve(vector<int>&curr , vector<bool>&visited ,
               vector<int>&arr , vector<vector<int>>&ans){

        if(curr.size() == arr.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0 ; i < arr.size() ; i++){

            if(visited[i]) continue;

            if(i>0 && arr[i]==arr[i-1] && !visited[i-1]) continue;

            visited[i] = true;

            curr.push_back(arr[i]);

            solve(curr , visited , arr , ans);

            curr.pop_back();

            visited[i] = false;
        }
    }

    void nextPermutation(vector<int>& nums) {

        vector<vector<int>> ans;

        vector<int> curr;

        vector<bool> visited(nums.size() , false);

        vector<int> arr = nums;

        sort(arr.begin() , arr.end());

        solve(curr , visited , arr , ans);

        int index = -1;

        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == nums){
                index = i;
                break;
            }
        }

        index = (index + 1) % ans.size();

        nums = ans[index];   // update nums
    }
};

Step 1 — Sort the array  - This gives the first permutation in lexicographic order.
Step 2 — Generate all permutations 
Step 3 — Find current permutation - You search where the given array exists.
Step 4 — Move to the next permutation
Step 5 — Handle wrap-around - If we are at the last permutation: (index + 1) % total_permutations


// optimal approach 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // Step 1: Find the pivot
        // Pivot = first index from right where nums[i] < nums[i+1]
        // This means the sequence after that index is in decreasing order
        // Example: 1 3 5 4 2
        //              ↑
        // pivot = index of 3

        int pivot = -1;

        for(int i = nums.size() - 1 ; i > 0 ; i--){
            if(nums[i-1] < nums[i]){
                pivot = i - 1;
                break;
            }
        }

        // Step 2: If pivot not found
        // The array is completely in descending order
        // Example: 5 4 3 2 1
        // The next permutation is the smallest permutation
        // So reverse the whole array

        if(pivot == -1){
            reverse(nums.begin() , nums.end());
            return;
        }

        // Step 3: Find element just larger than nums[pivot]
        // We search from the right side because the suffix is in descending order
        // The first element greater than pivot is the smallest valid swap

        int swap_index = -1;

        for(int i = nums.size() - 1 ; i > pivot ; i--){
            if(nums[i] > nums[pivot]){
                swap_index = i;
                break;
            }
        }

        // Step 4: Swap pivot with the next greater element
        swap(nums[pivot] , nums[swap_index]);

        // Step 5: Reverse the suffix after pivot
        // Because the suffix was in descending order
        // Reversing it makes it the smallest possible order

        reverse(nums.begin() + pivot + 1 , nums.end());
    }
};