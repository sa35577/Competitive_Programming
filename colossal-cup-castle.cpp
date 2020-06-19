#include <bits/stdc++.h>
using namespace std;


int main() {
    string sti;
    cin >> sti;
    bool bad = false;
    
    for (int i = 0; i < sti.size(); i++) {
        if (sti[i] != sti[sti.size()-i-1]) {
            bad = true;
            cout << "Unhappy Zhehai";
            break;
        }
    }
    if (!bad) cout << "Happy Zhehai";
}