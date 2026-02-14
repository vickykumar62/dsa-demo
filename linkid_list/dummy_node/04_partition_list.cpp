class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        // If list is empty
        if(head==nullptr) return nullptr;

        // Dummy node for smaller values list
        ListNode* dummySmall = new ListNode(-1);
        ListNode* preSmall = dummySmall;

        // Dummy node for larger/equal values list
        ListNode* dummyLarge = new ListNode(-1);
        ListNode* preLarge = dummyLarge;

        // Traverse original list
        while(head){
            
            if(head->val < x){
                // Attach current node to small list
                preSmall->next = head;
                preSmall = preSmall->next;
            }
            else{
                // Attach current node to large list
                preLarge->next = head;
                preLarge = preLarge->next;
            }

            // Move forward in original list
            head = head->next;
        }

        // ⚠ VERY IMPORTANT
        // End the large list properly
        preLarge->next = nullptr;

        // Connect small list to large list
        preSmall->next = dummyLarge->next;

        // Return head of new partitioned list
        return dummySmall->next;
    }
};
