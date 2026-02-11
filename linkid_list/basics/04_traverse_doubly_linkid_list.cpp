// Traversing the doubly Linked List 
void traverse(node* head){
    
    // Start from head node
    node* temp = head;
    
    // Loop until we reach NULL
    while(temp){
        
        // Print current node data
        cout << temp->data << " ";
        
        // Move to next node
        temp = temp->next;
    }
}
