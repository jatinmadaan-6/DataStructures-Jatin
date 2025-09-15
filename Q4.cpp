#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "aabc";
    int hash[26] = {0};
    queue<char> q;

    for(char ch : s) {
        hash[ch-'a']++;
        q.push(ch);

        while(!q.empty() && hash[q.front()-'a'] > 1) {
            q.pop();
        }

        if(q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }

    return 0;
}
d