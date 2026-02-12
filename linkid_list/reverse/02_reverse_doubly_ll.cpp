class Solution {
public:
    ListNode* reverseDLList(ListNode* head) {

        if(head==nullptr) return nullptr;

        ListNode* pre = nullptr;

        while(head){
            ListNode* curr = head;
            head = head->next;

            // Reverse next pointer
            curr->next = pre;

            // Fix back pointer of previous node
            if(pre != nullptr)
                pre->back = curr;

            // Set current node's back pointer
            curr->back = head;

            // Move pre forward
            pre = curr;
        }
        
        return pre;
    }
};
