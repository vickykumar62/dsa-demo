// Insert node at beginning in Singly Linked List
node* insert_first(node* head, int val){

    // Create new node
    node* temp = new node(val);

    // New node points to current head
    temp->next = head;

    // Return new node as new head
    return temp;
}
