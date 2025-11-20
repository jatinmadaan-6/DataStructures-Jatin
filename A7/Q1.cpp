#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {
        int m = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[m]) m = j;
        }
        swap(a[i], a[m]);
    }
}

void insertionSort(vector<int> &a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > x) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void bubbleSort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void mergeArr(vector<int> &a, int l, int m, int r) {
    vector<int> L(a.begin()+l, a.begin()+m+1), R(a.begin()+m+1, a.begin()+r+1);
    int i = 0, j = 0, k = l;
    while(i < L.size() && j < R.size()) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i < L.size()) a[k++] = L[i++];
    while(j < R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    mergeArr(a, l, m, r);
}

int partitionArr(vector<int> &a, int l, int r) {
    int p = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(a[j] <= p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quickSort(vector<int> &a, int l, int r) {
    if(l < r) {
        int pi = partitionArr(a, l, r);
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b;

    b = a;
    selectionSort(b);
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";

    b = a;
    insertionSort(b);
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";

    b = a;
    bubbleSort(b);
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";

    b = a;
    mergeSort(b, 0, n-1);
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";

    b = a;
    quickSort(b, 0, n-1);
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}
