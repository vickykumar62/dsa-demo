class Solution {
public:

    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        
        // If list is empty
        if(head == nullptr) 
            return nullptr;

        ListNode* pre = nullptr;   // This will become new head after reversal

        // Traverse the list
        while(head){
            
            ListNode* curr = head;   // Store current node
            
            head = head->next;       // Move head forward
            
            curr->next = pre;        // Reverse the link
            
            pre = curr;              // Move pre forward
        }

        // 'pre' will be new head of reversed list
        return pre;
    }

    bool isPalindrome(ListNode* head) {

        // If only one node → always palindrome
        if(head->next==nullptr) return true;

        // If exactly two nodes → check if equal
        if(head->next && head->next->next==nullptr 
           && head->val==head->next->val) 
            return true;

        // Slow and fast pointer to find middle
        ListNode* fast = head;
        ListNode* slow = head;

        // Find middle of linked list
        while(fast && fast->next){
            slow = slow->next;          // move slow by 1
            fast = fast->next;          // move fast by 1
            if(fast) fast = fast->next; // move fast one more (total 2)
        }

        // If fast == nullptr → even length
        if(fast==nullptr){ 

            // Reverse from slow (start of second half)
            ListNode* head1 = reverseList(slow);

            // Compare first half and reversed second half
            while(head1){
                if(head->val!=head1->val) 
                    return false;

                head = head->next;
                head1 = head1->next;
            }
            return true;
        }
        else{
            // If odd length → skip middle node
            ListNode* head1 = reverseList(slow->next);

            // Compare both halves
            while(head1){
                if(head->val!=head1->val) 
                    return false;

                head = head->next;
                head1 = head1->next;
            }
            return true;
        }

        return true;
    }
};

// if fast end at nullptr , it means even number of nodes , dry run to catch this
// and if it end at nullptr it means it odd number of nodes 

// find the middle node 
// reverse the second half
// now compare it with the first half