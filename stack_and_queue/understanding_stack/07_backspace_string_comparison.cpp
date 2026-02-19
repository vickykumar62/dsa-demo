class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st;

        // ---- Process first string s ----
        for(int i = 0; i < s.size(); i++){
            
            // If '#' and stack not empty → simulate backspace
            if(s[i] == '#' && !st.empty())
                st.pop();
            
            else {
                // If not '#' → normal character → push
                if(s[i] != '#')
                    st.push(s[i]);
            }
        }

        // Build final processed string for s
        string temp1 = "";
        while(!st.empty()){
            temp1 += st.top();
            st.pop();
        }

        // ---- Process second string t ----
        for(int i = 0; i < t.size(); i++){
            
            if(t[i] == '#' && !st.empty())
                st.pop();
            else{
                if(t[i] != '#')
                    st.push(t[i]);
            }
        }

        // Build final processed string for t
        string temp2 = "";
        while(!st.empty()){
            temp2 += st.top();
            st.pop();
        }

        // Compare final strings
        return temp1 == temp2;
    }
};

Normal character → push to stack

'#' → remove previous character (pop)

If stack empty and '#' → ignore

So stack represents the current typed string.
