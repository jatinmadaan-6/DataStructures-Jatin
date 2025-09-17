#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

bool isCircular(Node* head) {
    if (!head) return true;
    Node* t = head->next;
    while (t && t != head) t = t->next;
    return (t == head);
}

int main() {
    Node* head = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    head->next=n1; n1->next=n2; n2->next=head;
    cout << (isCircular(head) ? "Yes" : "No") << "\n";
}
