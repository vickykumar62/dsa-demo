class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        // If list is empty, nothing to remove
        if(head==nullptr) return nullptr;

        // Create a dummy node to handle edge cases 
        // (like deleting the original head)
        ListNode* dummy = new ListNode(-1);

        // 'pre' will build the new filtered list
        // Initially it points to dummy
        ListNode* pre = dummy;

        // Traverse the original list using 'head'
        while(head!=nullptr){

            // If current node value equals val → remove it
            if(head->val==val){

                // Store current node to delete later
                ListNode* temp = head;

                // Move head forward (skip current node)
                head = head->next;

                // Break connection from previous node
                // (temporarily sets next to NULL)
                pre->next = nullptr;

                // Break connection of deleted node completely
                temp->next = nullptr;

                // Free memory
                delete temp; 
            }
            else{
                // If value is not equal to val,
                // attach this node to our new list

                pre->next = head;  // connect previous node to current
                pre = head;        // move 'pre' forward
                head = head->next; // move traversal forward
            }
        }

        // Return the new head (which is next of dummy)
        return dummy->next;
    }
};
