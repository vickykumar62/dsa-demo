node* delete_first(node* head){

    if(head == nullptr) return nullptr;

    node* temp = head;
    head = head->next;

    delete temp;

    return head;
}
