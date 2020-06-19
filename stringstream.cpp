#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    stringstream ss(s);
    string tok;
    int tot = 0;
    while (getline(ss,tok,' ')) {
        cout << stoi(tok) << endl;
        tot += stoi(tok);
    }
    cout << "total: " << tot << endl;
}