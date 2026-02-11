// Insert node at beginning in Doubly Linked List
node* insert_first(node* head, int val){

    // Case 1: Empty list
    if(head == nullptr)
        return new node(val);

    // Create new node
    node* temp = new node(val);

    // Connect new node forward to old head
    temp->next = head;

    // Connect old head backward to new node
    head->back = temp;

    // New node becomes head
    return temp;
}
