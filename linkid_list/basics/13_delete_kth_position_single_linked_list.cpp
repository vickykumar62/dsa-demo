node* delete_kth(node* head, int idx){

    if(head == nullptr) return nullptr;

    // Delete head (index 1)
    if(idx == 1){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* temp = head;
    node* pre = nullptr;
    int count = 1;

    while(temp){

        if(count == idx){
            pre->next = temp->next;
            delete temp;
            return head;
        }

        pre = temp;
        temp = temp->next;
        count++;
    }

    return head;
}
