class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        
        // Stack will store bracket numbers of '('
        stack<int> st;
        
        vector<int> ans;
        
        // count gives unique number to each '('
        int count = 0;
        
        for(int i = 0; i < str.size(); i++){
            
            // If opening bracket
            if(str[i] == '('){
                
                // Assign new number
                count += 1;
                
                // Push this number into stack
                // So that matching ')' can use it
                st.push(count);
                
                // Store number for '(' in answer
                ans.push_back(count);
            }
            
            // If closing bracket
            else if(str[i] == ')'){
                
                // Matching bracket number is on top
                ans.push_back(st.top());
                
                // Remove matched '('
                st.pop();
            }
        }
        
        return ans;
    }
};

We want:

Every pair of matching brackets to have the same number
Numbers should increase for every new opening bracket