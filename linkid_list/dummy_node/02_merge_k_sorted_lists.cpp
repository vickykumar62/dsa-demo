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

ListNode* mergeKLists(vector<ListNode*>& lists) {

    if(lists.size() == 0) 
        return nullptr;

    // Start with first list
    ListNode* head = lists[0];

    // Merge one by one
    for(int i = 1; i < lists.size(); i++){
        head = mergeTwoLists(head, lists[i]);
    }

    return head;
}

};


// optimize version usinng the prority queue

class Solution {
public:

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // Min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();
        if(n == 0) return nullptr;

        // Min heap storing ListNode*
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push first node of each list (if not NULL)
        for(int i = 0; i < n; i++){
            if(lists[i] != nullptr)
                pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){

            ListNode* node = pq.top();
            pq.pop();

            // Attach smallest node
            temp->next = node;
            temp = temp->next;

            // If next node exists, push into heap
            if(node->next != nullptr)
                pq.push(node->next);
        }

        return dummy->next;
    }
};
