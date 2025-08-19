#include <bits/stdc++.h>
using namespace std;

int findMissing(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1; 
    }
    return low + 1;  
}
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissing(arr, n);
    cout << missing << endl;

    return 0;
}
