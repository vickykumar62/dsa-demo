class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Step 1: Find length of both lists
        int n1 = 0;
        int n2 = 0;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1){
            n1++;
            temp1 = temp1->next;
        }

        while(temp2){
            n2++;
            temp2 = temp2->next;
        }

        // Step 2: Reset pointers to heads
        temp1 = headA;
        temp2 = headB;

        // Step 3: Move the pointer of longer list ahead by difference
        if(n2 > n1){
            int diff = n2 - n1;
            for(int i = 0 ; i < diff ; i++){
                temp2 = temp2->next;
            }
        }
        else{
            int diff = n1 - n2;
            for(int i = 0 ; i < diff ; i++){
                temp1 = temp1->next;
            }
        }

        // Step 4: Move both pointers together
        // When they meet → intersection node
        while(temp1){
            if(temp1 == temp2)  // Compare addresses, not values
                return temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // No intersection
        return NULL;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while(p1 != p2){
            p1 = (p1 == NULL) ? headB : p1->next;
            p2 = (p2 == NULL) ? headA : p2->next;
        }

        return p1;

    }
};

Let both pointers traverse both lists fully.

This automatically aligns them.

Case 1: Intersection Exists

After switching lists:

Both pointers have equal remaining distance to intersection.

They meet at intersection node.

Case 2: No Intersection

Both pointers:

Finish List A

Finish List B

Become NULL