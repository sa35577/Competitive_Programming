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
    int h,w;
    cin >> h >> w;
    string arr[h];
    rep(i,0,h,1) cin >> arr[i];
    int dp[h][w];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    rep(i,1,h,1) {
        if (arr[i][0] == '#') break;
        dp[i][0] = 1;
    }
    rep(i,1,w,1) {
        if (arr[0][i] == '#') break;
        dp[0][i] = 1;
    }
    rep(i,1,h,1) {
        rep(j,1,w,1) {
            if (arr[i][j] == '#') continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] = dp[i][j] % MOD;
        }
    }
    cout << dp[h-1][w-1] << endl;

}