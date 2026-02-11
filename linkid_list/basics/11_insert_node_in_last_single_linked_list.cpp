// 7️⃣ Insert node at last in Singly Linked List
node* insert_last(node* head, int val){

    // Case 1: If list is empty
    if(head == nullptr)
        return new node(val);

    // Start from head
    node* temp = head;

    // Traverse till last node
    while(temp->next){
        temp = temp->next;
    }

    // Create new node and attach it at the end
    temp->next = new node(val);

    // Head does not change
    return head;
}
