#include <bits/stdc++.h>
using namespace std;

typedef struct {
    char arr[100];
    int top;
} Mystack;

void init(Mystack &s) {
    s.top = -1;
}

void push(Mystack &s, char x) {
    if (s.top >= 99) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    s.top++;
    s.arr[s.top] = x;
}

char pop(Mystack &s) {
    if (s.top == -1) {
        return '\0'; // Return null if underflow
    }
    char val = s.arr[s.top];
    s.top--;
    return val;
}

bool isEmpty(Mystack &s) {
    return (s.top == -1);
}

bool isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

bool isBalanced(string expr) {
    Mystack st;
    init(st);

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(st, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(st)) return false; 
            char topChar = pop(st);
            if (!isMatchingPair(topChar, ch)) return false;
        }
    }
    return isEmpty(st); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "has balanced parentheses." << endl;
    else
        cout << "does NOT have balanced parentheses." << endl;

    return 0;
}
