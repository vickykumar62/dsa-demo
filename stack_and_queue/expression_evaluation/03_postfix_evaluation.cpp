#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s) {

    stack<int> st;

    for(int i = 0; i < s.length(); i++) {

        char ch = s[i];

        // If operand → push to stack
        if(isdigit(ch)) {
            st.push(ch - '0');  // convert char to int
        }

        // If operator
        else {

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

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


If operand → push into stack
If operator →
Pop TWO elements
Do operation
Push result back

Because postfix is: Operand Operand Operator


