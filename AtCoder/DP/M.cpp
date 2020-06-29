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
const ll MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

int N,K;
ll dp[100005];
ll P[100005];


ll calculate(int stepBack, int cur) {
    if (stepBack < 0) {
        stepBack = 0;
    }
    ll ret = P[cur];
    if (stepBack > 0) ret -= P[stepBack-1];
    return (ret + MOD) % MOD;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    dp[0] = 1;
    rep(var,1,N+1,1) {
        int val;
        cin >> val;
        P[0] = dp[0];
        dp[0] = 0;
        for (ll i = 1; i <= K; i++) {
            P[i] = (P[i-1] + dp[i]) % MOD;
        }
        for (ll i = 0; i <= K; i++) dp[i] = calculate(i-val,i);
    }
    cout << (dp[K] + MOD) % MOD;
}


