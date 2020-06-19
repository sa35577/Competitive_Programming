#include <bits/stdc++.h>
 
typedef unsigned long long ll;
using namespace std;
 
const ll MOD = 1000000007;

unordered_map<ll,ll> Fib;
 
ll fib(ll n)
{
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end()) return Fib[n] % MOD;
    Fib[n] = ((fib((n+1) / 2) % MOD)*(fib(n/2) % MOD) + (fib((n-1) / 2) % MOD)*(fib((n-2) / 2) % MOD)) % MOD;
    return Fib[n] % MOD;
}

ll mod(string num, ll a) {
    ll res = 0;
    for (int i = 0; i < num.length(); i++) {
        res = (res*10 + (int)num[i]-'0') % a;
    }
    return res;
}

int main()
{
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    
    ll n = mod(s,2000000016);
    
    

}   