class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // If list has 0 or 1 node, nothing to change
        if(head == nullptr || head->next == nullptr)
            return head;

        // odd starts from first node
        ListNode* odd = head;

        // even starts from second node
        ListNode* even = head->next;

        // store start of even list
        ListNode* evenHead = even;

        // Traverse while even and even->next exist
        while(even && even->next){

            // Connect odd to next odd
            odd->next = even->next;
            odd = odd->next;

            // Connect even to next even
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list at the end of odd list
        odd->next = evenHead;

        return head;
    }
};