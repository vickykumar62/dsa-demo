class Solution {
  public:

    // Function to check how many students are required
    // if each student can read at most 'max_pages'
    int countStudents(vector<int> &books, int max_pages){

        int students = 1;
        int pages = 0;

        for(int &b : books){

            // if adding this book exceeds limit
            if(pages + b > max_pages){

                students++;   // allocate to new student
                pages = b;
            }
            else{
                pages += b;
            }
        }

        return students;
    }

    int findPages(vector<int> &books, int m) {

        int n = books.size();

        // If students > books allocation impossible
        if(m > n) return -1;

        // minimum pages must be largest book
        int low = *max_element(books.begin(), books.end());

        // maximum pages = sum of all books
        int high = accumulate(books.begin(), books.end(), 0);

        int ans = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            int students_needed = countStudents(books, mid);

            // too many students required
            if(students_needed > m){
                low = mid + 1;
            }

            // allocation possible
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Key Observation

// If we allow maximum pages = X:

// If allocation is possible, then larger values will also work.
// If allocation is not possible, smaller values will also fail.

// So we get a monotonic search space → perfect for Binary Search.

// search space : 
// low  = max(books)
// high = sum(books)

// why?

// max(books) → one student must read the largest book
// sum(books) → one student reads all books

// Binary Search Logic

// Try a candidate:

// mid = maximum pages allowed per student

// Check:

// How many students are needed if each can read at most mid pages?

// Decision:

// students_needed > m
// → mid too small → increase

// students_needed ≤ m
// → mid works → try smaller