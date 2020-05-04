//
// Created by satcl on 2020-05-04.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD  = 1000000007;


struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        ll hash1 = hash<T1>{}(p.first);
        ll hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<ll,ll>,ll,hash_pair> coeff;

ll fastPow(ll base, ll power) {
    ll result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}

ll Coeff(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    if (coeff.find({n,k}) != coeff.end()) return coeff[{n,k}];
    //if (2*k > n) return coeff[{n,n-k}];
    coeff[{n,k}] = (((Coeff(n,k-1) % MOD) * (n-k+1) % MOD) * fastPow(k,MOD-2)) % MOD;
    return coeff[{n,k}];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    ll r,c;
    for (int k = 0; k < t; k++) {
        cin >> r >> c;
        ll base = 0,tot = 0;
        for (ll i = c; i >= 0; i--) {
            if (i & 1) tot -= (Coeff(c,i)*fastPow(base,r)) % MOD;
            else tot += (Coeff(c,i)*fastPow(base,r)) % MOD;
            base = (base * 2 + 1) % MOD;
            tot = (tot + MOD) % MOD;
        }
        cout << (tot + MOD) % MOD<< "\n";

    }
}