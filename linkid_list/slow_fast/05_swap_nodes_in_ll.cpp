class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // If list is empty
        if(head == nullptr) return head;

        // fast pointer will move k steps first
        ListNode* fast = head;

        // Move fast to kth node from start
        for(int i = 1; i < k; i++){
            fast = fast->next;
        }

        // Store kth node from start
        ListNode* first = fast;

        // slow starts from head
        ListNode* slow = head;

        // Move both fast and slow together
        // until fast reaches last node
        while(fast->next){

            fast = fast->next;   // move fast forward
            slow = slow->next;   // move slow forward
        }

        // Now:
        // slow is kth node from end
        ListNode* second = slow;

        // Swap values of first and second nodes
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};


If two pointers have a gap of k nodes,
when front pointer reaches end,
back pointer will be k nodes behind.