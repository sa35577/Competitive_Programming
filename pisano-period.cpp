#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll a = 1, b = 2, PERIOD = 2, MOD = 1000000007;
    ll c;
    while (true) {
        c = a+b;
        a = b;
        b = c;
        a %= MOD;
        b %= MOD;
        c %= MOD;
        if (a == 1 && b == 1) break;
        else if (PERIOD > 2000000020) break;
        PERIOD++;
    }   
    cout << PERIOD << "\n";
}