#include<bits/stdc++.h>
using namespace std;

void interleavequeue(queue<int>& q)
{
    if(q.size()%2 != 0){cout<< "invalid";
    return; }
    int half = q.size()/2;

    queue<int> firsthalf;
    for(int i=0;i<half;i++)
    {
        firsthalf.push(q.front());
        q.pop();
    }
   while (!firsthalf.empty()) {
        q.push(firsthalf.front());
        firsthalf.pop();

        q.push(q.front());
        q.pop();
    }
};

int main()
{
     queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleavequeue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;

}