#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data= val;
        next = nullptr;
    }
};

Node* findMiddle(Node* head)
{
  Node* i= head;
  Node* j=head;
  while(j && j->next)
  {
    i=i->next;
    j=j->next->next;

  }
  return i;
}



int main()
{

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next= new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

   Node* ans = findMiddle(head);
   cout<< ans->data;

   return 0;

}
