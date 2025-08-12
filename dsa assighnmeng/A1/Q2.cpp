#include<bits/stdc++.h>
using namespace std;

// //with STL
// int main()
// {
//     int arr[12] = {2,2,2,5,5,6,8,7,9,9,9,10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//      set<int> unique(arr,arr+n);

//    cout << "unique Elements"<<endl;
//    for(auto it:unique)
//    {
//     cout << it << " ";
//    }
//    cout << endl;

//    return 0;

// }

//without STL

int main()
{   
    int arr[12] = {2,2,2,5,5,6,8,7,9,9,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    for(int i=0;i<n;i++)
     {
        for(int j = i+1; j<n ;j++)
           {
             if(arr[j]==arr[i])
             {
                for(int k=j ; k<n-1 ; k++)
                 {
                    arr[k]=arr[k+1];
                 }
                 n--;
                 j--;
             }
            

           }

     }
         cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;

}