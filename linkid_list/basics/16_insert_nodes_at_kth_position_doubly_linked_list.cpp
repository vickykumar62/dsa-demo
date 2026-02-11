// Insert at Kth position in Doubly Linked List (1-based index)
node* insert_kth(node* head, int idx, int val){

    if(idx <= 0)
        return head;

    node* newNode = new node(val);

    // Insert at beginning
    if(idx == 1){
        newNode->next = head;

        if(head != nullptr)
            head->back = newNode;

        return newNode;
    }

    node* temp = head;
    node* pre = nullptr;
    int count = 1;

    // Traverse to Kth position
    while(temp && count < idx){
        pre = temp;
        temp = temp->next;
        count++;
    }

    // If idx is beyond length+1
    if(count != idx){
        delete newNode;
        return head;
    }

    // Insert node
    pre->next = newNode;
    newNode->back = pre;

    newNode->next = temp;

    if(temp != nullptr)
        temp->back = newNode;

    return head;
}
