// Develop a menu driven program demonstrating the following operations on simple 
//Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek(). 
#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int arr[10];
    int front = -1;
    int back = -1;
    int count = 0;

    void enqueue(int x);
    void dequeue();
    bool isempty();
    bool isfull();
    void display();
    void peek();
};

void Queue::enqueue(int x) {
    if (isfull()) {
        cout << "Overflow\n";
        return;
    }
    if (isempty()) { 
        front = back = 0;
    } else {
        back++;
    }
    arr[back] = x;
    count++;
}

void Queue::dequeue() {
    if (isempty()) {
        cout << "Underflow\n";
        return;
    }
    cout << "Removed: " << arr[front] << endl;
    front++;
    count--;

    if (count == 0) {
        front = back = -1;
    }
}

bool Queue::isempty() {
    return (count == 0);
}

bool Queue::isfull() {
    return (count == 10);
}

void Queue::display() {
    if (isempty()) {
        cout << "Queue is empty\n";
        return;
    }
    for (int i = front; i <= back; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Queue::peek() {
    if (isempty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << arr[front] << endl;
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();  
    q.peek();    

    q.dequeue();  
    q.display();  
}
