// Delete Kth node in Doubly Linked List (1-based index)
node* delete_kth(node* head, int idx){

    // Case 1: Empty list
    if(head == nullptr)
        return nullptr;

    // Case 2: Invalid index
    if(idx <= 0)
        return head;

    node* temp = head;
    node* pre = nullptr;
    int count = 1;

    // If deleting first node
    if(idx == 1){
        head = head->next;

        if(head != nullptr)
            head->back = nullptr;

        delete temp;
        return head;
    }

    // Traverse to Kth node
    while(temp && count < idx){
        pre = temp;
        temp = temp->next;
        count++;
    }

    // If idx > length
    if(temp == nullptr)
        return head;

    // Now:
    // pre  = (k-1)th node
    // temp = kth node

    // Fix forward link
    pre->next = temp->next;

    // Fix backward link (if not last node)
    if(temp->next != nullptr){
        temp->next->back = pre;
    }

    delete temp;

    return head;
}
