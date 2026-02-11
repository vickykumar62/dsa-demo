class node{
public:
    int data;        // stores value of node
    node* next;      // pointer to next node

    // Constructor to initialize node
    node(int val){
        data = val;      // assign value
        next = nullptr;  // initially next is NULL
    }
};

// 1. Convert array to singly linked list
node* arr_l(vector<int>& nums){
    
    // Edge Case:
    // If array is empty, no nodes can be created
    if(nums.size() == 0) return nullptr;
    
    // Step 1: Create first node separately
    // Because head must always point to first node
    node* head = new node(nums[0]);
    
    // 'pre' will always point to last created node
    node* pre = head;
    
    // Step 2: Create remaining nodes
    for(int i = 1; i < nums.size(); i++){
        
        // Create new node
        node* temp = new node(nums[i]);
        
        // Attach previous node to this new node
        pre->next = temp;
        
        // Move previous pointer forward
        pre = temp;
    }
    
    // Return head of linked list
    return head;
}
