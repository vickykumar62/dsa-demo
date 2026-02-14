class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // If list is empty → no cycle possible
        if(head==nullptr) return false;

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
            if(fast) fast = fast->next;

            // If slow and fast meet → cycle exists
            if(slow==fast){
                return true;
            }
        }

        // If fast reaches NULL → no cycle
        return false ;
    }
};
