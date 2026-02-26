class Solution {
public:

    /*
    Build prefix maximum array.
    leftMax[i] = maximum height from index 0 → i
    */
    void solve1(vector<int>& height , vector<int>& leftMax , int n){

        int max_val = height[0];   // store maximum seen so far

        for(int i = 0 ; i < n ; i++){
            max_val = max(max_val, height[i]);  // update running maximum
            leftMax[i] = max_val;               // store it
        }
    }

    /*
    Build suffix maximum array.
    rightMax[i] = maximum height from index i → n-1
    */
    void solve2(vector<int>& height , vector<int>& rightMax , int n){

        int max_val = height[n-1];   // start from rightmost element

        for(int i = n-1 ; i >= 0 ; i--){
            max_val = max(max_val, height[i]);  // update running maximum
            rightMax[i] = max_val;              // store it
        }
    }

    int trap(vector<int>& height) {

        int n = height.size();
        if(n == 0) return 0;   // edge case

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Step 1: Fill prefix max
        solve1(height, leftMax, n);

        // Step 2: Fill suffix max
        solve2(height, rightMax, n);

        int ans = 0;

        /*
        For each index:
        Water stored = min(max height on left, max height on right)
                       - current height

        Because water level is limited by the smaller boundary.
        */
        for(int i = 0 ; i < n ; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};

