#include <bits/stdc++.h>
using namespace std;

int main() {
    string alphabet = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int k;
    cin >> k;
    string inp;
    cin >> inp;
    for (int i = 0; i < inp.length(); i++) {
        cout << find(alphabet.begin(),alphabet.end(),inp[i]) << endl;
    }
}
