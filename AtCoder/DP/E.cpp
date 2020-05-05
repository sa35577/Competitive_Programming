//
// Created by satcl on 2020-05-05.
//
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


/*---END OF TEMPLATE---*/




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n,w;
    //scan(n); scan(w);
    cin >> n >> w;
    int dp[n+2][w+2];
    memset(dp,0,sizeof(dp));
    rep(i,1,n+1,1) {
        int wei,val;
        //scan(wei);
        //scan(val);
        cin >> wei >> val;
        rep(j,wei,w+1,1) {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-wei]+val);
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
    }
    int mx = -1;
    rep(j,0,w+1,1) mx = max(mx,dp[n][j]);
    cout << mx << endl;
    rep(i,0,n+1,1) {
        rep(j,0,w+1,1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}