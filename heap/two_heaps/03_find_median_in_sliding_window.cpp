class Solution {
public:

    // ----------------------------------------------------
    // Balance both heaps so that
    // left size = right size OR left = right + 1
    // ----------------------------------------------------
    void balance(priority_queue<int> &left_max_heap,
                 priority_queue<int , vector<int> , greater<int>> &right_min_heap){

        // if left becomes too big
        if(left_max_heap.size() > right_min_heap.size() + 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }

        // if right becomes bigger
        else if(right_min_heap.size() > left_max_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }


    // ----------------------------------------------------
    // Insert number into correct heap
    // ----------------------------------------------------
    void add(int num,
             priority_queue<int> &left_max_heap,
             priority_queue<int , vector<int> , greater<int>> &right_min_heap){

        // if number belongs to smaller half
        if(left_max_heap.empty() || num <= left_max_heap.top())
            left_max_heap.push(num);

        // otherwise goes to larger half
        else
            right_min_heap.push(num);

        // after insertion maintain heap sizes
        balance(left_max_heap, right_min_heap);
    }


    // ----------------------------------------------------
    // Remove element from heap
    // since heap doesn't support arbitrary deletion
    // we recursively search and rebuild the heap
    // ----------------------------------------------------
    void remove(int num,
                priority_queue<int> &left_max_heap,
                priority_queue<int , vector<int> , greater<int>> &right_min_heap){

        // case 1: element is top of left heap
        if(!left_max_heap.empty() && num == left_max_heap.top()){
            left_max_heap.pop();
        }

        // case 2: element is top of right heap
        else if(!right_min_heap.empty() && num == right_min_heap.top()){
            right_min_heap.pop();
        }

        // case 3: element somewhere inside left heap
        else if(!left_max_heap.empty() && num < left_max_heap.top()){

            int temp = left_max_heap.top();
            left_max_heap.pop();

            remove(num, left_max_heap, right_min_heap);

            left_max_heap.push(temp);
        }

        // case 4: element somewhere inside right heap
        else{

            int temp = right_min_heap.top();
            right_min_heap.pop();

            remove(num, left_max_heap, right_min_heap);

            right_min_heap.push(temp);
        }

        // after deletion we must rebalance
        balance(left_max_heap, right_min_heap);
    }


    // ----------------------------------------------------
    // Compute median from heaps
    // ----------------------------------------------------
    double get_ans(priority_queue<int> &left_max_heap,
                   priority_queue<int , vector<int> , greater<int>> &right_min_heap){

        // if both heaps equal size
        if(left_max_heap.size() == right_min_heap.size()){

            // avoid integer overflow
            return ((long long)left_max_heap.top() +
                    (long long)right_min_heap.top()) / 2.0;
        }

        // left heap has one extra element
        return (double)left_max_heap.top();
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        priority_queue<int> left_max_heap;
        priority_queue<int , vector<int> , greater<int>> right_min_heap;

        vector<double> ans;

        // ------------------------------------------------
        // build first window
        // ------------------------------------------------
        for(int i = 0 ; i < k ; i++)
            add(nums[i], left_max_heap, right_min_heap);

        ans.push_back(get_ans(left_max_heap, right_min_heap));

        // ------------------------------------------------
        // slide window
        // ------------------------------------------------
        for(int i = k ; i < nums.size() ; i++){

            // remove element leaving window
            remove(nums[i-k], left_max_heap, right_min_heap);

            // add new element
            add(nums[i], left_max_heap, right_min_heap);

            ans.push_back(get_ans(left_max_heap, right_min_heap));
        }

        return ans;
    }
};

// 1. Insert new element
// 2. Remove old element
// 3. Balance heaps
// 4. Compute median