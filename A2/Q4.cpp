#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


void concatenate() {
    char str1[100], str2[100];
    cout << "Enter first string";
    cin >> str1;
    cout << "Enter second string";
    cin >> str2;
    strcat(str1, str2);
    cout << "final string " << str1 << endl;
}


void reverseString() {
    char str[100];
    cout << "Enter a string";
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
    cout << "Reversed string" << str << endl;
}


bool isVowel(char c) {
    c = tolower(c);
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
    return false;
}

void deleteVowels() {
    char str[100], result[100];
    cout << "Enter a string";
    cin >> str;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';
    cout << "final String" << result << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings";
    cin >> n;
    char arr[50][100];
    cout << "Enter " << n << " strings\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    cout << "Strings\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}


void upperToLower() {
    char ch;
    cout << "Enter an uppercase character";
    cin >> ch;
    cout << "Lowercase " << (char)tolower(ch) << endl;
}


int main() {
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Concatenate strings\n";
    cout << "2. Reverse string\n";
    cout << "3. Delete vowels\n";
    cout << "4. Sort strings\n";
    cout << "5. Uppercase to lowercase\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: concatenate(); break;
        case 2: reverseString(); break;
        case 3: deleteVowels(); break;
        case 4: sortStrings(); break;
        case 5: upperToLower(); break;
        default: cout << "Invalid choice\n";
    }

    return 0;
}