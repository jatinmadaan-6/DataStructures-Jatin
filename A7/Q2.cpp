#include <bits/stdc++.h>
using namespace std;

void improvedSelectionSort(vector<int> &a) {
    int l = 0, r = a.size() - 1;
    while(l < r) {
        int mn = l, mx = r;
        for(int i = l; i <= r; i++) {
            if(a[i] < a[mn]) mn = i;
            if(a[i] > a[mx]) mx = i;
        }
        swap(a[l], a[mn]);
        if(mx == l) mx = mn;
        swap(a[r], a[mx]);
        l++;
        r--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    improvedSelectionSort(a);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
