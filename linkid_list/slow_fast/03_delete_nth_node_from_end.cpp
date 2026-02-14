class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // If list is empty
        if(head==nullptr) return nullptr;

        // Fast pointer starts from head
        ListNode* fast = head;

        // Move fast pointer n steps ahead
        // This creates a gap of n nodes between fast and slow
        for(int i = 1 ; i <= n ; i++){
            if(fast){
                fast = fast->next;
            }
        }

        // If fast becomes NULL after moving n steps,
        // it means we need to remove the first node
        if(fast==nullptr) return head->next;

        // Slow pointer starts from head
        ListNode* slow = head;

        // Move both pointers until fast reaches last node
        // When fast->next is NULL,
        // slow will be just before the node to delete
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node from end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};

Imagine two people running on a track:

 Fast starts first

 Slow starts from beginning

Fast is always n steps ahead

Now both walk at same speed.

When fast reaches the finish line…

Slow will be exactly n steps behind finish line

Create n gap between two pointers.
Move together.