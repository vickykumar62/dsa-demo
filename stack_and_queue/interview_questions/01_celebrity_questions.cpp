class Solution {
  public:

    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();

        stack<int> st;

        // Push all people into stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }

        /*
        Elimination Process:

        If A knows B → A cannot be celebrity
        If A does not know B → B cannot be celebrity
        */
        while(st.size() >= 2){

            int first = st.top();
            st.pop();

            int second = st.top();
            st.pop();

            if(mat[first][second] == 1){
                // first knows second → first not celebrity
                st.push(second);
            }
            else{
                // first does not know second → second not celebrity
                st.push(first);
            }
        }

        // If no candidate left
        if(st.empty()) return -1;

        int candidate = st.top();

        /*
        Final Verification:

        1. Candidate should not know anyone.
        2. Everyone should know candidate.
        */

        for(int i = 0; i < n; i++){

            if(i == candidate) continue;

            // If candidate knows someone
            if(mat[candidate][i] == 1)
                return -1;

            // If someone does not know candidate
            if(mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};

// optimal in o(1) space complexcity
int celebrity(vector<vector<int>>& mat) {

    int n = mat.size();
    int candidate = 0;

    // Step 1: Find possible candidate
    for(int i = 1; i < n; i++){
        if(mat[candidate][i] == 1) // candidate knows i means candidate can not be celebrity because celebrity don't know any one 
            candidate = i;
    }

    // Step 2: Verify candidate
    for(int i = 0; i < n; i++){
        if(i == candidate) continue;

        if(mat[candidate][i] == 1 || mat[i][candidate] == 0)
            return -1;
    }

    return candidate;
}

