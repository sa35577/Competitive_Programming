#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/
//The torture chamber

bool isPrime(ll x) {
    if (x % 2 == 0) return false;
    if (x == 3 || x == 5 || x == 7) return true;
    for (ll i = 3; i*i <= x; i+=2) {
        if (x%i == 0) {
            return false;
        }
    }
    return true;
}

ll sieve(ll x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (x < 5) return 2;
    if (x < 7) return 3;
    if (x < 11) return 4;
    vll primes;
    ll y = (ll)sqrt(x);
    ll bounds[y];
    bounds[0] = y;
    for (ll i = 1; i < y; i++) {
        bounds[i] = bounds[i-1] + y; 
    }
    bounds[y-1] = x;
    primes.push_back(2);
    for (ll i = 3; i <= y; i += 2) {
        if (isPrime(i)) primes.push_back(i);
    }
    ll tot = primes.size();
    unordered_map<ll,ll> curPrimes;
    

}





int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    ll a,b;
    cin >> a >> b;


}