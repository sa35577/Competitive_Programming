#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll x) {
    if (x == 0 && x == 1) return false;
    if (x % 2 == 0) return false;
    for (ll i = 3; i*i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
pair<ll,ll> primeTwo (ll mx) {
    ll n = (mx+1)/2;
    while (n < mx-2) {
        if (isPrime(n) && isPrime(mx-n)) {
            return {mx-n,n};
        }
        ++n;
    }
    return {0,0};
}

pair<ll,pair<ll,ll>> primeThree(ll mx) {
    ll n = (mx+1)/3;
    while (n < mx) {
        if (isPrime(n)) {
            pair<ll,ll> res = primeTwo(mx-n);
            if (res.first != 0 && res.second != 0 && n >= res.second && res.second >= res.first) {
                return {res.first,{res.second,n}};
            }
        }
        ++n;
    }
    return {0,{0,0}};

}

int main(){
    for (ll i = 0; i < 5; i++) {
        ll n;
        cin >> n;
        if (isPrime(n)) {
            cout << n << " = " << n << endl;

        }
        else {
            if (n % 2 == 0) {
                pair<ll,ll> twoPair = primeTwo(n);
                if (twoPair.first != 0 && twoPair.second != 0) {
                    cout << n << " = " << twoPair.first << " + " << twoPair.second << endl;
                }
                else {
                    pair<ll,pair<ll,ll>> threePair = primeThree(n);
                    cout << n << " = " << threePair.first << " + " << threePair.second.first << " + " << threePair.second.second << endl;
                }
            }
            else {
                pair<ll,pair<ll,ll>> threePair = primeThree(n);
                cout << n << " = " << threePair.first << " + " << threePair.second.first << " + " << threePair.second.second << endl;
            }
        }
    }
    
}