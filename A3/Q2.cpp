#include <bits/stdc++.h>
using namespace std;

typedef struct r {
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
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    char val = s.arr[s.top];
    s.top--;
    return val;
}

string reverseString(string &str) {
    Mystack st;
    init(st);

   
    for (char ch : str) {
        push(st, ch);
    }


    string reversed = "";
    while (st.top != -1) {
        reversed += pop(st);
    }

    return reversed;
}

int main() {
    string s = "HelloWorld";
    cout << "Original String: " << s << endl;
    cout << "Reversed String: " << reverseString(s) << endl;
    return 0;
}
