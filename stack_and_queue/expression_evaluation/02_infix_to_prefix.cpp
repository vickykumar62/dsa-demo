#include <bits/stdc++.h>
using namespace std;

// Function to return precedence
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {

    // Step 1: Reverse the string
    reverse(s.begin(), s.end());

    // Step 2: Swap '(' and ')'
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string result = "";

    // Step 3: Convert to Postfix
    for(int i = 0; i < s.length(); i++) {

        char ch = s[i];

        // If operand → add to result
        if(isalnum(ch)) {
            result += ch;
        }

        // If '(' → push
        else if(ch == '(') {
            st.push(ch);
        }

        // If ')'
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // If operator
        else {
            while(!st.empty() &&
                  precedence(st.top()) >= precedence(ch)) {
                result += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Step 4: Reverse result to get prefix
    reverse(result.begin(), result.end());

    return result;
}

1. Reverse the infix string
2. Swap '(' with ')'
3. Convert to Postfix
4. Reverse the result