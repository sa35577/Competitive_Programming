#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main() {
    ull pow2[60];
    pow2[0] = 1;
    for (int i = 1; i < 60; i++) {
        pow2[i] = 2*pow2[i-1];
    }
    ull n;
    cin >> n;
    int ind = 0;
    ull sum = 1;
    while (true) {
        if (sum <= n && sum+pow2[ind+1] > n) break;
        sum += pow2[ind+1];
        ++ind;
    }
    ull rem = n-sum;
    if (rem == 0) {
        cout << ind+1 << endl;
        for (int i = 0; i <= ind; i++) {
            cout << pow2[i] << " ";
        }
    }
    else if (rem >= pow2[ind]) {
        cout << ind+2 << endl;
        for (int i = 0; i <= ind; i++) {
            cout << pow2[i] << " ";
        }
        cout << rem;
    }
    else if (rem == 1) {
        cout << ind+2 << endl;
        cout << rem << " ";
        for (int i = 0; i <= ind; i++) {
            cout << pow2[i] << " ";
        }
    }
    else {
        cout << ind+2 << endl;
        for (int i = 0; i <= ind; i++) {
            if (pow2[i] >= rem && pow2[i-1] < rem) cout << rem << " ";
            cout << pow2[i] << " ";
        }
    }
}