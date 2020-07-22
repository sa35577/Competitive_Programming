#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
//#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
//#define p pair<int,int>
const ll MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int N;
const int MAXN = 25,MAXSZ = 1 << 21 + 1;
int arr[MAXN][MAXN];
int dp[MAXSZ];


int main() {
    scan(N);
    int powN = 1 << N; 
    rep(i,0,N,1) {
        rep(j,0,N,1) {
            scan(arr[i][j]);    
        }
    }
    dp[0] = 1;
    rep(powNum,0,powN-1,1) {
        int m = __builtin_popcount(powNum);
        rep(i,0,N,1) {
            if (arr[m][i] && !(powNum & (1 << i))) {
                dp[powNum | (1 << i)] = (dp[powNum | (1 << i)] + dp[powNum]) % MOD; 
            }
        }
        
    }
    cout << dp[powN-1];


}