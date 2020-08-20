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
//#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/
int n;
ll m;
const int MAXN = 100005;
vector<int> tree[MAXN];
ll dp1[MAXN],dp2[MAXN],prevs[MAXN];

ll dfs(int cur, int p) {
    for (int x : tree[cur]) {
        if (x != p) {
            dp1[cur] = (dp1[cur] * (dfs(x,cur) + 1)) % m;
        }
    }
    return dp1[cur];
}

void dfs2(int cur, int p, int val) {
    dp2[cur] = val;
    ll nxt = 1LL;
    for (int x : tree[cur]) {
        if (x != p) {
            prevs[x] = nxt % m;
            nxt = (nxt * (dp1[x]+1)) % m;
        }
    }
    nxt = 1;
    for (int idx = tree[cur].size()-1; idx >= 0; idx--) {
        int x = tree[cur][idx];
        if (x != p) {
            dfs2(x,cur,((val*prevs[x]) % m * nxt + 1) % m);
            nxt = (nxt * (dp1[x]+1)) % m;
        }
    }


}



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> n >> m;
    int v1,v2;
    rep(i,0,n-1,1) {
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    rep(i,0,MAXN,1) {
        dp1[i] = 1;
    }
    dfs(1,1);
    dfs2(1,1,1);
    rep(i,1,n+1,1) cout << (dp1[i]*dp2[i]) % m << endl;
}
