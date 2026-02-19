class Solution {
public:
    bool isValid(string s) {
        
        // Stack will store opening brackets
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            
            // If current character is closing bracket
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                
                // If stack is empty → no matching opening bracket
                if(st.empty()) return false;

                /*
                Now check if top of stack matches
                the corresponding opening bracket
                */
                
                if( (s[i] == ')' && st.top() != '(') ||
                    (s[i] == '}' && st.top() != '{') ||
                    (s[i] == ']' && st.top() != '[') )
                {
                    return false;  // Mismatch
                }
                else{
                    st.pop();  // Matched pair → remove opening bracket
                }
            }
            else{
                // If opening bracket → push into stack
                st.push(s[i]);
            }
        }

        // If stack is empty → all brackets matched
        return st.size() == 0;
    }
};


What is the idea?
Opening brackets → push
Closing brackets → match with top
If match → pop
If mismatch → invalid
At end → stack must be empty

MISTAKE :
Forgetting to check st.empty() before st.top()
Returning true without checking if stack is empty at end