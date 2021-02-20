#include <bits/stdc++.h>

using namespace std;

int main() {
    locale loc;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            cout << tolower(s[i],loc);
        }
        cout << "\n";
    }
    return 0;
}