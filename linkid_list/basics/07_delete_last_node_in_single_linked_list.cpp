// 4️⃣ Delete last node in Single Linked List
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

    // Traverse till last node
    while(temp->next){
        pre = temp;
        temp = temp->next;
    }

    // Break link of second last node
    pre->next = nullptr;

    // Delete last node
    delete temp;

    return head;
}
