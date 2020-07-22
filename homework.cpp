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
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/
bool isPrime(int i) {
    if (i < 0) return 0;
    if (i == 2 || i == 3 || i == 5) return 1;
    rep(k,2,sqrt(i),1) {
        if (i % k == 0) return 1;
    }
    return 0;
}


vi segmentedSieve(int L, int R) {
    int limit = R;
    vector<bool> mark(limit + 1, false);
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) //all multiples before it have been accounted for
                mark[j] = true;
        }
    }

    vector<int> vals(R - L + 1, 0);
    for (int i : primes) {
        for (int j = i*(R/i); j <= R; j += i) {
            if (j - L >= 0 && j - L <= R-L) {
                vals[j - L]++;
                
            }
            if (isPrime(j/i)) {
                    vals[j - L]++;
            }
        }
    }
    rep(i,L,R+1,1) {
        if (isPrime(i)) {
            vals[i-L]++;
        }
    }
    
    return vals;
}



int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int tc;
    scan(tc);
    rep(i,0,tc,1) {
        int a,b,k;
        scan(a);
        scan(b);
        scan(k);
        vi cur = segmentedSieve(a,b);
        int tot = 0;
        for (int i : cur) {
            cout << i << " ";
            if (i == k) ++tot;
        }
        printf("\nCase #%d: %d\n",tc+1,tot);
    }

}