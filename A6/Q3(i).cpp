#include <bits/stdc++.h>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int x) { data = x; next = prev = NULL; }
};

int size(DNode* head) {
    int cnt = 0;
    while (head) { cnt++; head = head->next; }
    return cnt;
}

int main() {
    DNode* head = new DNode(10);
    head->next = new DNode(20);
    head->next->prev = head;
    head->next->next = new DNode(30);
    head->next->next->prev = head->next;
    cout << size(head) << "\n";
}
