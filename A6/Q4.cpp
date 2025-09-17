#include <bits/stdc++.h>
using namespace std;

class DNode {
public:
    char data;
    DNode* next;
    DNode* prev;
    DNode(char x) { data = x; next = prev = NULL; }
};

bool isPalindrome(DNode* head) {
    if (!head) return true;
    DNode* tail = head;
    while (tail->next) tail = tail->next;
    while (head && tail && head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    DNode* a = new DNode('r');
    DNode* b = new DNode('a');
    DNode* c = new DNode('d');
    DNode* d = new DNode('a');
    DNode* e = new DNode('r');
    a->next=b; b->prev=a;
    b->next=c; c->prev=b;
    c->next=d; d->prev=c;
    d->next=e; e->prev=d;
    cout << (isPalindrome(a) ? "True" : "False") << "\n";
}
