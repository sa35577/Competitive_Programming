#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>
#include <random>

using namespace std;

#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vull vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/


mt19937_64 gen(time(NULL));
ll primers[100005];


/*ll fastPow(ll base, ll power, ll mod) {
    ll res = 1;
    while (power > 0) {
        if (power & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return res;
}*/
ll fastMul(ll x, ll y, ll mod) {
    if (!y) return (ll)0;
    return (x * (y & 1) + fastMul((x + x) % mod, y >> 1, mod)) % mod;
}
ll fastPow(ll x, ll y, ll mod) {
    if (!y) return 1LL;
    return fastMul((y & 1 ? x : 1), fastPow(fastMul(x, x, mod), y >> 1, mod), mod);
}

bool genPrime(ll n) {
    if (n <= 2) return 2;
    if (n == 3) return 3;
    if (n == 5) return 5;

    

    uniform_int_distribution<ll> randint((ll)2,n);
    rep(i,0,100,1) {
        //flt
        ll val = randint(gen);
        if (val == n) i--;
        else {
            if (fastPow(val,n-1,n) != 1) {
                return false;    
            }  
        }
    }
    return true;

}

int main() {


    ll n;
    cin >> n;
    if (n == 1) {
        printf("2\n"); return 0;
    }
    int ind = 0;
    ll cur = 2;
    while (ind != 100005) {
        if (genPrime(cur)) {
            primers[ind++] = cur;
            if (n == cur) {
                cout << n << endl;
                return 0;
            }
        }
    }

    while (1) {
        bool flag = false;
        if (n > primers[100005-1]) {
            rep(i,0,100005,1) {
                if (n % primers[i] == 0) {
                    flag = true;
                }
            }
        }
        if (!flag && genPrime(n)) {
            printf("%lld\n",n);
            break;
        }
        else n++;
    }
    return 0;

}
