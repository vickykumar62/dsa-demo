// Delete first node in Doubly Linked List
node* delete_first(node* head){
    
    // Case 1: Empty list
    if(head == nullptr) return nullptr;
    
    node* temp = head;
    
    // Move head forward
    head = head->next;
    
    // If list is not empty after deletion
    if(head != nullptr){
        head->back = nullptr;
    }
    
    delete temp;
    
    return head;
}
