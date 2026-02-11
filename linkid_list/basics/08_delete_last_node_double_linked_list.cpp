// Delete last node in Doubly Linked List 
node* delete_last(node* head){

    // Case 1: Empty list
    if(head == nullptr)
        return nullptr;

    // Case 2: Only one node
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    node* temp = head;
    node* pre = nullptr;

    // Traverse to last node
    while(temp->next){
        pre = temp;       // store previous node
        temp = temp->next;
    }

    // Now:
    // temp = last node
    // pre  = second last node

    pre->next = nullptr;   // break forward link
    temp->back = nullptr;  // break backward link (good practice)

    delete temp;

    return head;
}
