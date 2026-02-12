class Solution {
public:

    // Function to find the kth node from current head
    // Returns NULL if less than k nodes are present
    ListNode* findKthNode(ListNode* head , int k){
        ListNode* temp = head;
        int count = 1;

        // Move k-1 steps forward
        while(count < k && temp){
            temp = temp->next;
            count++;
        }

        // If temp becomes NULL before reaching k nodes,
        // it means less than k nodes are available
        return temp;
    }


    // Standard function to reverse a linked list
    // Returns new head after reversal
    ListNode* reverse(ListNode* head){
        if(head == nullptr) return nullptr;

        ListNode* pre = nullptr;

        while(head){
            ListNode* curr = head;
            head = head->next;

            curr->next = pre;   // Reverse pointer
            pre = curr;         // Move pre forward
        }

        return pre; // New head after reversal
    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr) return nullptr;

        ListNode* previousNode = nullptr;  // To connect previous group
        ListNode* nextNode = nullptr;      // To store next group's start
        ListNode* temp = head;             // Start of current group

        while(temp){

            // Step 1: Find kth node from current group start
            ListNode* kthNode = findKthNode(temp, k);

            // If less than k nodes left → don't reverse
            if(kthNode == nullptr){
                if(previousNode)
                    previousNode->next = temp; // connect remaining nodes
                break;
            }

            // Step 2: Store next group's starting node
            nextNode = kthNode->next;

            // Break the group
            kthNode->next = nullptr;

            // Step 3: Reverse current k group
            ListNode* newHead = reverse(temp);

            // Step 4: Connect previous group to current reversed group
            if(temp == head)
                head = newHead;   // First group → update head
            else
                previousNode->next = newHead;

            // Step 5: Update previousNode
            previousNode = temp;  // temp becomes tail after reversal

            // Step 6: Move to next group
            temp = nextNode;
        }

        return head;
    }
};

While(temp):
    find kth
    if less than k → break
    store nextGroup
    cut group
    reverse group
    connect previous group
    move temp to nextGroup