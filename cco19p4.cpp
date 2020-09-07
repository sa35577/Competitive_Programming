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
#define ld long double
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int n,k;
const int MAXN = 1000010;
int cnt[MAXN],arr[MAXN];
ld dp[MAXN],power[MAXN];
vi loc[MAXN];

void setPower() {
    power[0] = 0;
    rep(i,1,MAXN,1) {
        power[i] = pow(i,0.5*k);
    }
}

ld calc1(int idx, int v) {
    return dp[idx-1] + power[v-arr[idx]+1]; //moving forward using dp
}

ld calc2(int v1, int v2) {
    //how far forward (using index) until calc with v1 <= calc with v2 using binary search
    int L = 0, R = MAXN-1, mid;
    while (L <= R) {
        mid = (L+R)/2;
        if (calc1(v1,mid) > calc1(v2,mid)) R = mid-1; 
        else L = mid+1;
    }
    return R;
}

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(k); scan(n);
    setPower();
    dp[0] = 0.0;
    int val;
    rep(i,1,n+1,1) {
        scan(val);
        arr[i] = cnt[val]++;
        while (loc[val].size() > 1 && calc2(loc[val][loc[val].size()-2],loc[val].back()) <= calc2(loc[val].back(),i)) {
            loc[val].pop_back();
        }
        loc[val].push_back(i);
        while (loc[val].size() > 1 && calc1(loc[val][loc[val].size()-2],arr[i]) >= calc1(loc[val].back(),arr[i])) {
            loc[val].pop_back();
        } 
        dp[i] = calc1(loc[val].back(),arr[i]);
    }
    cout << setprecision(10) << dp[n] << endl;
    
}