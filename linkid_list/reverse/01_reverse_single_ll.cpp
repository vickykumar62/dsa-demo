class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // If list is empty
        if(head == nullptr) 
            return nullptr;

        ListNode* pre = nullptr;   // This will become new head

        // Traverse the list
        while(head){
            
            ListNode* curr = head;   // Store current node
            
            head = head->next;       // Move head forward
            
            curr->next = pre;        // Reverse the link
            
            pre = curr;              // Move pre forward
        }

        // pre will be new head of reversed list
        return pre;
    }
};
