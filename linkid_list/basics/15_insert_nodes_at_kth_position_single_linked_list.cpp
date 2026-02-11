// Insert at Kth position in Singly Linked List (1-based index)
node* insert_kth(node* head, int idx, int val){

    // Invalid index
    if(idx <= 0)
        return head;

    node* newNode = new node(val);

    // Insert at first position
    if(idx == 1){
        newNode->next = head;
        return newNode;
    }

    node* temp = head;
    node* pre = nullptr;
    int count = 1;

    // Traverse to Kth position
    while(temp && count < idx){
        pre = temp;
        temp = temp->next;
        count++;
    }

    // If idx is beyond length+1 → do nothing
    if(count != idx){
        delete newNode;
        return head;
    }

    // Insert node
    pre->next = newNode;
    newNode->next = temp;

    return head;
}
