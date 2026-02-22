class StockSpanner {
public:

    // Stack will store {price, span}
    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {

        int span = 1;  // At least today counts

        /*
        Pop all smaller or equal prices
        and accumulate their spans
        */
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }

        // Push current price with its span
        st.push({price, span});

        return span;
    }
};

// geeks for geeks 

class Solution {
  public:

    vector<int> calculateSpan(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);     // To store span for each day

        stack<int> st;          // Store indices of days
                                // Monotonic decreasing stack (by price)

        /*
        Traverse from left to right
        Because span depends on previous days
        */
        for(int i = 0; i < n; i++){

            /*
            Remove all previous prices that are
            less than or equal to current price,
            because they are included in today's span.
            */
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            /*
            If stack becomes empty:
            It means no greater price on left,
            so span = all days from 0 to i
            */
            if(st.empty()){
                ans[i] = i + 1;
            }
            else{
                /*
                If stack not empty:
                Top of stack gives index of previous greater price.
                Span = distance between current index
                       and previous greater index.
                */
                ans[i] = i - st.top();
            }

            // Push current index for future comparisons
            st.push(i);
        }

        return ans;
    }
};