#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
}

void heapSortInc(int a[], int n) {
    buildMaxHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;
    if (smallest != i) {
        int t = a[i];
        a[i] = a[smallest];
        a[smallest] = t;
        heapifyMin(a, n, smallest);
    }
}

void buildMinHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapifyMin(a, n, i);
}

void heapSortDec(int a[], int n) {
    buildMinHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapifyMin(a, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    heapSortInc(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    heapSortDec(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
