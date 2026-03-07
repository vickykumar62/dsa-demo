class Solution {
public:

    // Custom comparator to make MIN HEAP of ListNode*
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // smaller value should come first , in the cese of heap 
            // this comparison thing > work opposite 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();
        if(n == 0) return nullptr;

        // -------------------------------------------------
        // KEY IDEA:
        // Each linked list is already sorted.
        // So the smallest element must be among the HEADS
        // of all lists.
        //
        // Instead of pushing ALL nodes (which makes heap huge),
        // we push only the first node of each list.
        //
        // Heap size always stays ≤ k
        // -------------------------------------------------

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push the head of every list
        for(int i = 0; i < n; i++){
            if(lists[i] != nullptr)
                pq.push(lists[i]);
        }

        // Dummy node to simplify result list creation
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){

            // The smallest node among all current heads
            ListNode* node = pq.top();
            pq.pop();

            // Attach this node to result
            temp->next = node;
            temp = temp->next;

            // -------------------------------------------------
            // IMPORTANT TRICK:
            // Since we removed a node from its list,
            // the next node of that list becomes the new candidate.
            //
            // So we push node->next into heap.
            // -------------------------------------------------
            if(node->next != nullptr)
                pq.push(node->next);
        }

        return dummy->next;
    }
};