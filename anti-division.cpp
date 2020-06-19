#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
ll A,B,C,D;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C >> D;
    ll x = floor((double)B/C)-ceil((double)A/C);
    if ((double)A/C == (int)A/C) {
        x++;
    }
    ll y = floor((double)B/D)-ceil((double)A/D);
    if ((double)A/D == (int)A/D) {
        y++;
    }
    ll k = C*D;
    ll z = floor((double)B/k)-ceil((double)A/k);
    if ((double)A/k == (int)A/k) {
        z++;
    }
    cout << B-A+1 - (x+y-z);
}