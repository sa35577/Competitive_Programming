

#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
//#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const ll MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/
const int MAXN = 100005;
ll A[MAXN],B[MAXN],C[MAXN];


ll a(int n); ll b(int n); ll c(int n);

ll a(int n) {
    if (n < 1) return 0;
    if (A[n] != -1) return A[n];
    return A[n] = (a(n-1) + b(n-2) + a(n-5) + c(n-3)) % MOD;
}

ll b(int n) {
    if (n < 1) return 0;
    if (B[n] != -1) return B[n];
    return B[n] = (a(n-2) + c(n-3) + a(n-1) + b(n-2) + a(n-3) + b(n-4)) % MOD;
}

ll c(int n) {
    if (n < 1) return 0;
    if (C[n] != -1) return C[n];
    return C[n] = (a(n-1)*2 + a(n-2) + c(n-3) + b(n-2) + a(n-3) + b(n-4)) % MOD;
}

ll f(int n) {
    if (n <= 0) return 0;
    if (A[n] != -1) return A[n];
    return A[n] = (f(n-1) + f(n-3)) % MOD;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");

    memset(A,-1,sizeof(A)); memset(B,-1,sizeof(B)); memset(C,-1,sizeof(C));
    A[1] = 1;
    int n,m;
    cin >> n >> m;
    if (m == 1) printf("1\n");
    else if (m == 2) printf("%lld\n",f(n));
    else printf("%lld\n",a(n));
}
