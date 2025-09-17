#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

int size(Node* head) {
    if (!head) return 0;
    int cnt = 0;
    Node* t = head;
    do {
        cnt++;
        t = t->next;
    } while (t != head);
    return cnt;
}

int main() {
    Node* head = new Node(5);
    Node* n1 = new Node(15);
    Node* n2 = new Node(25);
    head->next = n1; n1->next = n2; n2->next = head;
    cout << size(head) << "\n";
}
