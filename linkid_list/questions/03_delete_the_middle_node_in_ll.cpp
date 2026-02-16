class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // If list is empty or has one node,
        // after deletion it becomes empty
        if(head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;   // To store node before slow

        // Move fast by 2 steps and slow by 1 step
        while(fast && fast->next){
            prev = slow;            // store previous
            slow = slow->next;      // move slow
            fast = fast->next->next;// move fast
        }

        // slow is now at middle
        // prev is node before middle

        prev->next = slow->next;    // remove middle node
        delete slow;                // free memory

        return head;
    }
};
