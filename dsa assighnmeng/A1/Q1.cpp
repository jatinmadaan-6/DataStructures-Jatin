#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int n = 0; 

void create() {
    cout << "Enter the desired size: ";
    cin >> n;
    if (n > MAX_SIZE) {
        cout << "Limit exceeded\n";
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (n == 0) {
        cout << "No Data Found\n";
        return;
    }
    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement() {
    int position, val;
    if (n >= MAX_SIZE) {
        cout << "Array size exceeded\n";
        return;
    }
    cout << "Enter position to insert (1 to " << n+1 << "): ";
    cin >> position;
    cout << "Enter value: ";
    cin >> val;

    if (position < 1 || position > n + 1) {
        cout << "Invalid position\n";
        return;
    }

    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = val;
    n++;
}

void deletion() {
    int position;
    if (n == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> position;

    if (position < 1 || position > n) {
        cout << "Invalid position\n";
        return;
    }

    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch() {
    int val;
    if (n == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Enter value to search: ";
    cin >> val;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Found at index " << i << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Element not in array\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deletion(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
