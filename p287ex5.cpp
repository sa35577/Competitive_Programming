#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (s[0] == '-') cout << s.size()-1 << "\n";
        else cout << s.size() << "\n";
    }
    return 0;
}