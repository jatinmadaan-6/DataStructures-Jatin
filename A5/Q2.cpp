#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
Node* RemoveOccurence(Node* head,int key)
{
    while(head != nullptr && head->data==key)
    {
        Node* todelete = head;
        head = head->next;
        delete(todelete);
    }
    Node *temp = head;
    Node* prev = nullptr;
    int count = 0;
    
    while(temp)
    {
        if(temp->data == key)
        {
            count++;
            prev->next = temp->next;
            delete(temp);
            temp=prev->next;
        }
        else
        {
            prev = temp;
            temp=temp->next;
        }
    }

    return head;
}

 int main()
{
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    cout << "Original list: ";
    Node* t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << "\n";

    head = RemoveOccurence(head, 2);

    cout << "After removal: ";
    t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << "\n";

    return 0;
}
