class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Dummy node to simplify result handling
        ListNode* dummy = new ListNode(-1);

        // 'pre' will move and build the new list
        ListNode* pre = dummy;

        int carry = 0;   // Stores carry from previous addition
        int sum = 0;     // Stores sum of current digits

        // Traverse both lists until both become NULL
        while(l1 || l2){

            // Start sum with previous carry
            sum += carry;

            // Add value from l1 if it exists
            if(l1) sum += l1->val;

            // Add value from l2 if it exists
            if(l2) sum += l2->val;

            // Create new node with single digit (sum % 10)
            ListNode* temp = new ListNode(sum % 10);

            // Attach node to result list
            pre->next = temp;
            pre = temp;

            // Update carry for next iteration
            carry = sum / 10;

            // Reset sum for next calculation
            sum = 0;

            // Move to next nodes if available
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }   

        // If carry remains after loop
        if(carry){
            ListNode* temp = new ListNode(carry);
            pre->next = temp;
        }

        // Return result list (skip dummy)
        return dummy->next;
    }
};
