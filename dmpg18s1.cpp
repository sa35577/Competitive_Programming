#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] == '0') {
        if (s.size() == 1) printf("Valid\n");
        else printf("Invalid\n");
        return 0;
    }

    int count0 = 0, count1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') ++count0;
        else if (s[i] == '1') ++count1;
    }
    if (count1 + count0 == s.size()) {
        if (count0 == 1 && s[s.size()-1] == '0') printf("Valid\n");
        else printf("Invalid\n");
        return 0;
    }
    int x = s[0]-'0';
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '0') x--;
    }
    if (x == 0) printf("Valid\n");
    else printf("Invalid\n");
    return 0;

}