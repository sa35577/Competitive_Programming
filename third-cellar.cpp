#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

vector<bool> segmentedSieve(ll L, ll R) {
    ll limit = sqrt(R);
    vector<bool> mark(limit + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= limit; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) //all multiples before it have been accounted for
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) isPrime[j - L] = 0;
    if (L == 1 && isPrime[0]) isPrime[0] = 0;
    return isPrime;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n;
    cin >> n;
    rep(i,0,n,1) {
        ll a,b;
        cin >> a >> b;
        ll res = 0;
        for (bool b : segmentedSieve(a,b-1)) {
            if (b) ++res;
        }
        cout << res << endl;
    }

}