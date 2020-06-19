#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000000;
const ll PISANO_PERIOD = 1500000000;
int a,b;


unordered_map<ll,ll> Fib;
 
ll fib(ll n)
{
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end()) return Fib[n] % MOD;
    Fib[n] = ((fib((n+1) / 2) % MOD)*(fib(n/2) % MOD) + (fib((n-1) / 2) % MOD)*(fib((n-2) / 2) % MOD)) % MOD;
    return Fib[n] % MOD;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll m;
    cin >> a >> b >> m;
    if (m == 0) {
        cout << a;
        return 0;
    }
    else if (m == 1) {
        cout << b;
        return 0;
    } 
    m -= 2;
    cout << (a * fib(m % PISANO_PERIOD) % MOD + b * fib((m+1) % PISANO_PERIOD) % MOD) % MOD;

    
}