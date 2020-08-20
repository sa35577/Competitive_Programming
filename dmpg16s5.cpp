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

int n,k;
vector<ll> v,dp;
ll mx = 0;

int idx(int i) {
    return (i + n) % n;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> n >> k;
    v.resize(n); dp.resize(n);
    dp[0] = 0;
    rep(i,0,n,1) {
        cin >> v[i];
        if (i < k) dp[i] += v[i];
    }
    ll mx = dp[0];
    rep(i,1,n,1) {
        dp[i] = dp[i-1] - v[i-1] + v[idx(i+k-1)];
        mx = max(mx,dp[i]);
    }
    cout << mx << endl;


}