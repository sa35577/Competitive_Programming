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
#define vull vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/


vector<bool> segmentedSieve(ull L, ull R) {
    ull limit = sqrt(R);
    vector<bool> mark(limit + 1, false);
    vector<ull> primes;
    for (ull i = 2; i <= limit; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (ull j = i * i; j <= limit; j += i) //aull multiples before it have been accounted for
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ull i : primes)
        for (ull j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) isPrime[j - L] = 0;
    if (L == 1 && isPrime[0]) isPrime[0] = 0;
    return isPrime;
}

int main() {
    ull a,b;
    cin >> a;
    b = a + 2000;
    vector<bool> sv = segmentedSieve(a,b);
    for (int i = 0; i < sv.size(); i++) {
        if (sv[i]) {
            cout << i + a << endl;
            break;
        }
    }

}