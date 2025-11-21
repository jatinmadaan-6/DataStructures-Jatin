#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

// (a) Search Recursive
Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// (a) Search Non-Recursive
Node* searchNonRec(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// (b) Maximum element in BST
Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}

// (c) Minimum element in BST
Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

// (d) In-order Successor
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL)
        return findMin(target->right);

    Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else break;
    }
    return successor;
}

// (e) In-order Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL)
        return findMax(target->left);

    Node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else break;
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 5, 15, 30, 25, 35};
    for (int x : arr) root = insertNode(root, x);

    int key = 15;

    Node* r1 = searchRec(root, key);
    Node* r2 = searchNonRec(root, key);

    cout << "Search Recursive: ";
    if (r1) cout << r1->data; else cout << "Not found";

    cout << "\nSearch Non-Recursive: ";
    if (r2) cout << r2->data; else cout << "Not found";

    cout << "\nMin: " << findMin(root)->data;
    cout << "\nMax: " << findMax(root)->data;

    Node* succ = inorderSuccessor(root, r1);
    if (succ) cout << "\nSuccessor of " << key << ": " << succ->data;
    else cout << "\nSuccessor: None";

    Node* pred = inorderPredecessor(root, r1);
    if (pred) cout << "\nPredecessor of " << key << ": " << pred->data;
    else cout << "\nPredecessor: None";

    return 0;
}
