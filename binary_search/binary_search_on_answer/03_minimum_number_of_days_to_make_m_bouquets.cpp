class Solution {
public:

    // Count how many bouquets we can make by day = mid
    int solve(vector<int>& bloomDay, int m, int k, int mid){

        long long bouquets = 0;
        long long count = 0;   // count adjacent bloomed flowers

        for(int i = 0; i < bloomDay.size(); i++){

            // flower has bloomed by day mid
            if(bloomDay[i] <= mid){
                count++;

                // if we collected k adjacent flowers
                if(count == k){
                    bouquets++;
                    count = 0;   // reset for next bouquet
                }
            }

            // adjacency breaks
            else{
                count = 0;
            }
        }

        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // total flowers needed
        long long total_flower_need = 1LL * m * k;

        // if not enough flowers
        if(total_flower_need > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // bouquets we can make by day = mid
            int bouquets = solve(bloomDay, m, k, mid);

            // day works
            if(bouquets >= m){
                ans = mid;
                high = mid - 1;
            }

            // need more days
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};