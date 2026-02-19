class Solution {
public:
    int minAddToMakeValid(string s) {
        
        // Stack will store unmatched brackets
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            
            // If opening bracket → push
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                // If closing bracket
                
                // If stack empty → no matching opening
                if(st.empty()){
                    st.push(s[i]);   // This closing is unmatched
                }
                else{
                    /*
                    If closing bracket matches top opening bracket
                    → remove matched pair
                    */
                    
                    if( (s[i] == ')' && st.top() == '(') ||
                        (s[i] == '}' && st.top() == '{') ||
                        (s[i] == ']' && st.top() == '[') )
                    {
                        st.pop();  // Valid pair
                    }
                    else{
                        // Mismatch → this bracket is also unmatched
                        st.push(s[i]);
                    }
                }
            }
        }

        // Remaining stack elements are unmatched brackets
        return st.size();
    }
};

We are counting:

Unmatched opening brackets

Unmatched closing brackets

Each unmatched bracket needs one extra bracket to fix it.

So final answer = number of unmatched brackets.

// optimal 

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        // open → counts unmatched '(' brackets
        int open = 0;
        
        // add → counts how many '(' we need to add
        // when we find unmatched ')'
        int add = 0;
        
        for(char c : s){
            
            // If opening bracket → increase open count
            if(c == '('){
                open++;
            }
            else{
                // If closing bracket ')'
                
                // If there is an unmatched '(' available,
                // we can match this ')' with one '('
                if(open > 0){
                    open--;   // Pair formed → reduce unmatched '('
                }
                else{
                    // No '(' available to match this ')'
                    // So we need to add one '(' before it
                    add++;
                }
            }
        }
        
        /*
        At the end:
        - open = number of unmatched '('
        - add  = number of unmatched ')'
        
        Total brackets needed = open + add
        */
        
        return open + add;
    }
};
