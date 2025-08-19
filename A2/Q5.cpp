#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of  matrix";
    cin >> n;

    
    int diag[n];
    cout << "\nEnter diagonal matrix elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "," << i << "]: ";
        cin >> diag[i];  
    }
    cout << "Diagonal matrix stored in 1D array:\n";
    for (int i = 0; i < n; i++) cout << diag[i] << " ";
    cout << endl;


    int tri[3*n - 2]; 
    cout << "\nEnter tri-diagonal matrix elements:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cout << "Element [" << i << "," << j << "]: ";
            cin >> val;
            if (abs(i - j) <= 1) {  
                tri[k++] = val;
            }
        }
    }
    cout << "Tri-diagonal matrix stored in 1D array:\n";
    for (int i = 0; i < k; i++) cout << tri[i] << " ";
    cout << endl;

    int lower[n*(n+1)/2];
    cout << "\nEnter lower triangular matrix elements:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int val;
            cout << "Element [" << i << "," << j << "]: ";
            cin >> val;
            lower[k++] = val;
        }
    }
    cout << "Lower triangular matrix stored in 1D array:\n";
    for (int i = 0; i < k; i++) cout << lower[i] << " ";
    cout << endl;

    int upper[n*(n+1)/2]; 
    cout << "\nEnter upper triangular matrix elements:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int val;
            cout << "Element [" << i << "," << j << "]: ";
            cin >> val;
            upper[k++] = val;
        }
    }
    cout << "Upper triangular matrix stored in 1D array:\n";
    for (int i = 0; i < k; i++) cout << upper[i] << " ";
    cout << endl;

   
    int sym[n*(n+1)/2];
    cout << "\nEnter symmetric matrix elements (lower triangle only):\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int val;
            cout << "Element [" << i << "," << j << "]: ";
            cin >> val;
            sym[k++] = val;
        }
    }
    cout << "Symmetric matrix stored in 1D array:\n";
    for (int i = 0; i < k; i++) cout << sym[i] << " ";
    cout << endl;

    return 0;
}
