class node{
public:
    int data;      // Stores value of the node
    node* next;    // Pointer to next node
    node* back;    // Pointer to previous node (only in doubly linked list)
    
    // Constructor 1: Create node with value
    node(int val){
        data = val;
        next = nullptr;  // initially no next node
        back = nullptr;  // initially no previous node
    }
    
    // Constructor 2: Create node with value + next + previous
    node(int val, node* next1, node* back1){
        data = val;
        next = next1;
        back = back1;
    }
};


// Convert Array → Doubly Linked List
node* arr_dl(vector<int>& nums){
    
    // If array is empty → no linked list
    if(nums.size() == 0) return nullptr;
    
    // Step 1: Create head node using first element
    node* head = new node(nums[0]);
    
    // 'pre' will track the previous node
    node* pre = head;
    
    // Step 2: Loop through remaining elements
    for(int i = 1; i < nums.size(); i++){
        
        // Create new node
        // next = nullptr (because it is last for now)
        // back = pre (connect backward)
        node* temp = new node(nums[i], nullptr, pre);
        
        // Connect previous node forward to temp
        pre->next = temp;
        
        // Move pre forward
        pre = temp;
    }
    
    // Return head of doubly linked list
    return head;
}
