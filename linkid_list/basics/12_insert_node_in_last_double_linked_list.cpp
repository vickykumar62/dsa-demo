// Insert node at last in Doubly Linked List
node* insert_last(node* head, int val){

    // Case 1: If list is empty
    if(head == nullptr)
        return new node(val);

    node* temp = head;

    // Traverse to last node
    while(temp->next){
        temp = temp->next;
    }

    // Create new node
    node* newNode = new node(val);

    // Connect last node forward
    temp->next = newNode;

    // Connect new node backward
    newNode->back = temp;

    return head;
}
