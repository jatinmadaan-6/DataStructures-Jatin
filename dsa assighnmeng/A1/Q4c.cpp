#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cout << "Enter number of rows and columns: ";
    cin >> a >> b;

    int arr[a][b];

    // Input matrix
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }

    // Print transpose
    cout << "Transpose of the matrix:\n";
    for (int j = 0; j < b; j++) {
        for (int i = 0; i < a; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
