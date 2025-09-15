#include<bits/stdc++.h>
using namespace std;
class circularqueue
{ 
    public:
    int front = -1;
    int rear = -1;
    int count =0;
    int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    void enqueue(int x)
    {
      if(count == 0 )
      {
        front++;
        rear++;
      }
      else if(count ==10)
      {
        cout<< "overflow";
        return;
      }
      else
      {
        rear = ((rear+1)%size);
      }
    arr[rear] = x;
    count++;



    }
    void dequeue()
    {
        if(count == 0)
        {
            cout<<"underflow";
            return;
        }
        cout << "Removed: " << arr[front] << endl;
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        count--;
        
    }

    bool isempty()
    {
        return(front == -1);
    }
    bool isfull()
    {
        return((rear+1)%size == front);
    }
    void display()
    {
        if(isempty())
        {
            cout<<"invalid";
            return;
        }
       int i = front;
       while(true)
       {
        cout<<arr[i];
        if(i==rear){
            break;
        }
        i=((i+1)%size);
       }
    }
    void peek()
    {
        if(isempty())
        {
            cout<<"invalid";
            return;
        }
        cout<<arr[front];

    }

     
};