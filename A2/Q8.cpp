#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array ";
    cin >> n;

    int arr[n];
    cout << "Enter elements ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> distinctElements;  
    for (int i = 0; i < n; i++) {
        distinctElements.insert(arr[i]);
    }

    cout << "Total number of distinct elements = " << distinctElements.size() << endl;

    return 0;
}
