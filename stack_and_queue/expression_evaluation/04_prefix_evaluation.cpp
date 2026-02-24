#include <bits/stdc++.h>
using namespace std;

int evaluatePrefix(string s) {

    stack<int> st;

    // Traverse from right to left
    for(int i = s.length() - 1; i >= 0; i--) {

        char ch = s[i];

        // If operand
        if(isdigit(ch)) {
            st.push(ch - '0');
        }

        // If operator
        else {

            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            int result = 0;

            if(ch == '+')
                result = a + b;
            else if(ch == '-')
                result = a - b;
            else if(ch == '*')
                result = a * b;
            else if(ch == '/')
                result = a / b;
            else if(ch == '^')
                result = pow(a, b);

            st.push(result);
        }
    }

    return st.top();
}

Traverse expression from RIGHT → LEFT
If operand → push into stack

If operator →
Pop TWO elements
Apply operation
Push result back
Final stack top is answer

Feature	         Postfix	         Prefix
Traversal	     Left → Right	     Right → Left
Pop order	     b then a	         a then b
Apply	         a op b	             a op b

If interviewer asks:

“Evaluate Reverse Polish Notation”

That means → POSTFIX

If they say:

“Evaluate Polish Notation”

That means → PREFIX