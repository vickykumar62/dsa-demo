class Solution {
public:

    // Reverse full linked list
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = nullptr;

        while(head){
            ListNode* curr = head;
            head = head->next;

            curr->next = pre;
            pre = curr;
        }

        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == nullptr || left == right)
            return head;

        // Step 1: Create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* previousNode = dummy;
        ListNode* temp = head;

        int count = 1;

        // Step 2: Move previousNode to node before left
        while(count < left){
            previousNode = temp;
            temp = temp->next;
            count++;
        }

        // Now:
        // previousNode → node before left
        // temp → node at left

        ListNode* first = temp;   // start of reverse part

        // Step 3: Move temp to right position
        while(count < right){
            temp = temp->next;
            count++;
        }

        ListNode* second = temp;       // end of reverse part
        ListNode* nextNode = temp->next;

        // Step 4: Cut the sublist
        previousNode->next = nullptr;
        second->next = nullptr;

        // Step 5: Reverse the isolated sublist
        ListNode* reversedHead = reverseList(first);

        // Step 6: Reconnect
        previousNode->next = reversedHead;

        // first is now tail after reversal
        first->next = nextNode;

        // Return actual head (dummy->next)
        return dummy->next;
    }
};

// Find boundaries → Cut → Reverse → Reconnect.
