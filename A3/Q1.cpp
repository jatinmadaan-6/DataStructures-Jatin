#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int oper[101];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        oper[++top] = x;
        cout << x << " pushed to stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        cout << oper[top] << " popped from stack." << endl;
        return oper[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 100;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << oper[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << oper[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n*** Stack Menu ***" << endl;
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 4:
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
