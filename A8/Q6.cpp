#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int a[100];
    int n;

    PriorityQueue() {
        n = 0;
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (a[p] < a[i]) {
                int t = a[p];
                a[p] = a[i];
                a[i] = t;
                i = p;
            } else break;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;
            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest != i) {
                int t = a[i];
                a[i] = a[largest];
                a[largest] = t;
                i = largest;
            } else break;
        }
    }

    void push(int x) {
        a[n] = x;
        heapifyUp(n);
        n++;
    }

    int top() {
        if (n == 0) return -1;
        return a[0];
    }

    void pop() {
        if (n == 0) return;
        a[0] = a[n-1];
        n--;
        heapifyDown(0);
    }

    bool empty() {
        return n == 0;
    }
};

int main() {
    PriorityQueue pq;
    int ch, x;
    while (true) {
        cin >> ch;
        if (ch == 1) {
            cin >> x;
            pq.push(x);
        }
        else if (ch == 2) {
            pq.pop();
        }
        else if (ch == 3) {
            cout << pq.top() << endl;
        }
        else if (ch == 4) {
            cout << (pq.empty() ? "Empty" : "Not Empty") << endl;
        }
        else break;
    }
    return 0;
}
