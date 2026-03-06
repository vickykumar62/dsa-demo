class MedianFinder {
public:

    // Max Heap → stores smaller half of numbers
    priority_queue<int> left_max_heap;

    // Min Heap → stores larger half of numbers
    priority_queue<int , vector<int> , greater<int>> right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // Step 1:
        // Decide where to place the number

        // If number is smaller than max of left side
        // it belongs to the left half
        if(left_max_heap.empty() || num < left_max_heap.top()) 
            left_max_heap.push(num);

        // Otherwise it belongs to right half
        else 
            right_min_heap.push(num);


        // Step 2:
        // Balance both heaps
        // Size difference should not exceed 1

        // Case 1:
        // Left heap became too large
        if(left_max_heap.size() - right_min_heap.size() > 1 ){

            // Move largest element of left to right
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }

        // Case 2:
        // Right heap became larger
        else if(right_min_heap.size() > left_max_heap.size()){

            // Move smallest element of right to left
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {

        // Case 1:
        // Even number of elements
        // Median = average of two middle elements
        if(left_max_heap.size() == right_min_heap.size())
            return (left_max_heap.top() + right_min_heap.top()) / 2.0;

        // Case 2:
        // Odd number of elements
        // Left heap will contain the extra element
        return left_max_heap.top();
        
    }
};

// To maintain the median of a stream, we divide numbers into two halves.
Max Heap (left)  → stores smaller half
Min Heap (right) → stores larger half

why ? Because we only care about the boundary elements:

// Rule 1
// Maintain two heaps
// left_max_heap  → smaller half
// right_min_heap → larger half

// Rule 2
// Size difference should never exceed 1

// Rule 3
// left_max_heap is allowed to have one extra element

// Rule 4
// Median cases
// if sizes equal → average of both tops
// else → top of left_max_heap

// Time Complexity
// addNum()    → O(log n)
// findMedian()→ O(1)

Whenever you see: Median in stream , Running median

MAX HEAP (left) + MIN HEAP (right)
Balance sizes
Median from tops