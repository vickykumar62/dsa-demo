class Solution {
public:
    ListNode* sort(ListNode* head){
        
        // If list is empty
        if(head==nullptr) return nullptr;

        // Create three dummy nodes for 0, 1, 2 lists
        ListNode* dummyZero = new ListNode(-1);
        ListNode* dummyOne  = new ListNode(-1);
        ListNode* dummyTwo  = new ListNode(-1);

        // These pointers will build each list
        ListNode* preZero = dummyZero;
        ListNode* preOne  = dummyOne;
        ListNode* preTwo  = dummyTwo;

        // Traverse original list
        while(head){
            
            if(head->val==0){
                // Attach node to zero list
                preZero->next = head;
                preZero = preZero->next;
            }
            else if(head->val==1){
                // Attach node to one list
                preOne->next = head;
                preOne = preOne->next;
            }
            else{
                // Attach node to two list
                preTwo->next = head;
                preTwo = preTwo->next;
            }

            // Move forward in original list
            head = head->next;
        }

        // Connect 0 list to 1 list (if exists), otherwise 2 list
        preZero->next = (dummyOne->next) ? dummyOne->next : dummyTwo->next;

        // Connect 1 list to 2 list
        preOne->next = dummyTwo->next;

        // Terminate 2 list properly
        preTwo->next = nullptr;

        // Head of sorted list
        ListNode* ans = dummyZero->next;

        return ans;
    }
};
