#include<bits/stdc++.h>
using namespace std;



int main()
{
    int m, n, p; 
    cout << "Enter rows and columns of first matrix (m n): ";
    cin >> m >> n;

    cout << "Enter columns of second matrix (p): ";
    cin >> p; 
    int A[m][n], B[n][p], C[m][p];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];


    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;
    
    for(int i=0;i<m;i++)
     {
        for(int j=0;j<p;j++)
         {
            for(int k=0;k<n;k++)
              {
                C[i][j] += A[i][k] * B[k][j];
              }
         }
     }
}