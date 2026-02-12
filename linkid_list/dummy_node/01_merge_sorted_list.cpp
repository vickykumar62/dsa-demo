class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Create a dummy node to simplify edge cases
        // (like when result list is empty initially)
        ListNode* dummy = new ListNode(-1);
        
        // Temp pointer will build the merged list
        ListNode* temp = dummy;

        // Traverse both lists until one becomes NULL
        while(list1 && list2){
            
            // Compare current nodes of both lists
            if(list1->val < list2->val){
                
                // Attach smaller node (list1)
                temp->next = list1;
                
                // Move list1 forward
                list1 = list1->next;
            }
            else{
                
                // Attach smaller node (list2)
                temp->next = list2;
                
                // Move list2 forward
                list2 = list2->next;
            }

            // Move temp forward in merged list
            temp = temp->next;
        }

        // Attach remaining list directly because they will be sorted 
        temp->next = (list1) ? list1 : list2;


        // Return head of merged list
        // (skip dummy node)
        return dummy->next;
    }
};

Dummy node avoids special case.

Always attach smaller node.

Move pointer of the list you used.

Attach leftover at the end.