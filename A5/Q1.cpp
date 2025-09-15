#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* insertatbeginning(Node* head, int x) {
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

Node* insertatend(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == nullptr) return temp; 
    Node* find = head;
    while (find->next != nullptr) {
        find = find->next;
    }
    find->next = temp;
    return head;
}

Node* insertinbetween(Node* head, int x, int position) {
    if (position == 1) return insertatbeginning(head, x);
    Node* find = head;
    int count = 1;
    while (find != nullptr && count < position - 1) {
        find = find->next;
        count++;
    }
    if (find == nullptr) return head; 
    Node* temp = new Node(x);
    temp->next = find->next;
    find->next = temp;
    return head;
}

Node* deletefrombeginning(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deletefromend(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* find = head;
    while (find->next->next != nullptr) {
        find = find->next;
    }
    delete find->next;
    find->next = nullptr;
    return head;
}

Node* deletebyposition(Node* head, int position) {
    if (position == 1) return deletefrombeginning(head);
    Node* find = head;
    int count = 1;
    while (find != nullptr && count < position - 1) {
        find = find->next;
        count++;
    }
    if (find == nullptr || find->next == nullptr) return head;
    Node* toDelete = find->next;
    find->next = toDelete->next;
    delete toDelete;
    return head;
}

void search(Node* head, int data) {
    Node* find = head;
    int count = 1;
    while (find) {
        if (find->data == data) {
            cout << "Found at position " << count << endl;
            return;
        }
        find = find->next;
        count++;
    }
    cout << "Not found" << endl;
}

void displayall(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    head = insertatbeginning(head, 10);
    head = insertatbeginning(head, 20);
    head = insertatend(head, 30);
    head = insertinbetween(head, 25, 3);

    cout << "Linked List: ";
    displayall(head);

    head = deletefrombeginning(head);
    head = deletefromend(head);
    head = deletebyposition(head, 2);

    cout << "After deletions: ";
    displayall(head);

    search(head, 25);
    search(head, 100);

    return 0;
}
