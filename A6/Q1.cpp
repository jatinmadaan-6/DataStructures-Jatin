#include <bits/stdc++.h>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DLL {
    DNode* head;
public:
    DLL() { head = NULL; }

    void insertFirst(int x) {
        DNode* n = new DNode(x);
        if (!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertLast(int x) {
        DNode* n = new DNode(x);
        if (!head) head = n;
        else {
            DNode* t = head;
            while (t->next) t = t->next;
            t->next = n;
            n->prev = t;
        }
    }

    void insertAfter(int key, int x) {
        DNode* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        DNode* n = new DNode(x);
        n->next = t->next;
        n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }

    void insertBefore(int key, int x) {
        if (!head) return;
        if (head->data == key) { insertFirst(x); return; }
        DNode* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        DNode* n = new DNode(x);
        n->next = t;
        n->prev = t->prev;
        t->prev->next = n;
        t->prev = n;
    }

    void deleteNode(int key) {
        DNode* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        if (t == head) head = head->next;
        if (t->prev) t->prev->next = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t;
    }

    bool search(int key) {
        DNode* t = head;
        while (t) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }

    void display() {
        DNode* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CLL {
    CNode* head;
public:
    CLL() { head = NULL; }

    void insertFirst(int x) {
        CNode* n = new CNode(x);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            CNode* t = head;
            while (t->next != head) t = t->next;
            n->next = head;
            t->next = n;
            head = n;
        }
    }

    void insertLast(int x) {
        CNode* n = new CNode(x);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            CNode* t = head;
            while (t->next != head) t = t->next;
            t->next = n;
            n->next = head;
        }
    }

    void insertAfter(int key, int x) {
        if (!head) return;
        CNode* t = head;
        do {
            if (t->data == key) {
                CNode* n = new CNode(x);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void insertBefore(int key, int x) {
        if (!head) return;
        if (head->data == key) { insertFirst(x); return; }
        CNode* t = head;
        do {
            if (t->next->data == key) {
                CNode* n = new CNode(x);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key && head->next == head) { delete head; head = NULL; return; }
        CNode* t = head, *prev = NULL;
        do {
            if (t->data == key) {
                if (t == head) {
                    CNode* last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                } else prev->next = t->next;
                delete t;
                return;
            }
            prev = t;
            t = t->next;
        } while (t != head);
    }

    bool search(int key) {
        if (!head) return false;
        CNode* t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void display() {
        if (!head) { cout << "\n"; return; }
        CNode* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << "\n";
    }
};

int main() {
    DLL dll;
    CLL cll;
    int choice, listType, x, key;
    while (true) {
        cout << "1.InsertFirst 2.InsertLast 3.InsertAfter 4.InsertBefore 5.Delete 6.Search 7.Display 8.Exit\n";
        cin >> choice;
        if (choice == 8) break;
        cout << "1.DLL 2.CLL\n";
        cin >> listType;
        switch (choice) {
            case 1: cin >> x; listType==1?dll.insertFirst(x):cll.insertFirst(x); break;
            case 2: cin >> x; listType==1?dll.insertLast(x):cll.insertLast(x); break;
            case 3: cin >> key >> x; listType==1?dll.insertAfter(key,x):cll.insertAfter(key,x); break;
            case 4: cin >> key >> x; listType==1?dll.insertBefore(key,x):cll.insertBefore(key,x); break;
            case 5: cin >> key; listType==1?dll.deleteNode(key):cll.deleteNode(key); break;
            case 6: cin >> key; cout << (listType==1?dll.search(key):cll.search(key)) << "\n"; break;
            case 7: listType==1?dll.display():cll.display(); break;
        }
    }
}
