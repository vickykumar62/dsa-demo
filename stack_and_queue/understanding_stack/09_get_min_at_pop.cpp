// Function to push elements and store minimum so far
stack<int> _push(int arr[], int n) {
    
    stack<int> st;
    
    // This will track minimum till current index
    int minimum = INT_MAX;
    
    for(int i = 0; i < n; i++){
        
        // Update minimum till this element
        minimum = min(minimum, arr[i]);
        
        /*
        Instead of pushing actual array element,
        we push the minimum till this point.
        
        So every position in stack stores:
        min(arr[0] ... arr[i])
        */
        st.push(minimum);
    }
    
    return st;
}


// Function to print minimum at each pop
void _getMinAtPop(stack<int> s) {

    /*
    Since stack contains prefix minimums,
    popping will print minimum at that stage.
    */
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
