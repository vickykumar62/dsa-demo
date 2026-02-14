class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        // If list is empty
        if(head==nullptr) return nullptr; 
        
        // If only one node exists
        if(head->next==nullptr) return head; 

        // Slow pointer moves 1 step
        ListNode* slow = head;

        // Fast pointer moves 2 steps
        ListNode* fast = head;

        // Traverse until fast reaches end
        while(fast && fast->next){

            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 1 step
            fast = fast->next;

            // Move fast one more step (total 2 steps)
            if(fast){
                fast = fast->next;
            }
        }

        // When fast reaches end,
        // slow will be at middle
        // If even length → slow lands on second middle
        return slow;
    }
};
