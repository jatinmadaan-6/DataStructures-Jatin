#include <bits/stdc++.h>
using namespace std;


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  
        case '^': return pow(a, b);
    }
    return 0;
}


int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0'); 
        } 
        else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result = applyOperation(val1, val2, c);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a Postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
