#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
unordered_map<long long,long long> mp;
long long x;

long long pow(long long base) {
    long long result = 1;
    long long power = 1000000005;
    while(power > 0) {
        if(power & 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1; 
    }
    return result;

}

long long fact(long long n) {
    if (n == 1) return 1;
    return ((n*fact(n-1)%MOD)%MOD) % MOD;
}
long long choose(long long k) {
    if (mp.find(k) != mp.end()) return mp[k];
    if (k == 1) {
        mp[k] = fact(x);
        return mp[k];

    }
    if (k == x) return 1;
    mp[k] = ((choose(k-1)%MOD * (x-k+1)%MOD)%MOD * (pow(k)%MOD * pow(k-1)%MOD)%MOD) % MOD;
    return mp[k];

}

int main() {
    cin >> x;
    long long tot = 0;
    for (long long i = 1; i <= x; i++) {
        tot += choose(i);
        tot %= MOD;
    }
    cout << tot %MOD;


}