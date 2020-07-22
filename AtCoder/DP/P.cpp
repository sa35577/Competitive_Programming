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
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int N;
const int MAXN = 100001;
vector<int> tree[MAXN];
ll dp[MAXN][2];
const int WHITE = 0, BLACK = 1;


ll solve(int v, int color, int parent) {
    if (v == 0) {
        return (solve(1,WHITE,0) + solve(1,BLACK,0)) % MOD;
    }
    ll tot = 1, totWhite, totBlack;
    if (dp[v][color] != -1) return dp[v][color];
    rep(i,0,tree[v].size(),1) {
        if (tree[v][i] != parent) {
            if (color == WHITE) {
                totBlack = solve(tree[v][i],BLACK,v);
            }
            else totBlack = 0;
            totWhite = solve(tree[v][i],WHITE,v);
            tot = (tot * (totWhite + totBlack)) % MOD;
        }
    }


    return dp[v][color] = tot;

    
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N);
    int v1,v2;
    rep(i,0,N-1,1) {
        scan(v1); scan(v2);
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    memset(dp,-1,sizeof(dp));
    cout << solve(0,0,0);


}