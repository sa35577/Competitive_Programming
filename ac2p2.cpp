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
int N;
const int MAXN = 505;
string A[MAXN];
int dp[MAXN][MAXN];

void floyd() {
    rep(i,1,N+1,1) {
        rep(j,1,N+1,1) {
            rep(k,1,N+1,1) {
                if (dp[i][k] != -1 && dp[k][j] != -1) {
                    if (dp[i][j] == -1) {
                        cout << i << " " << j << " " << k << endl;
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                    /*else if (dp[i][k] + dp[k][j] > dp[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }*/
                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N;
    memset(dp,-1,sizeof(dp));
    rep(i,1,N+1,1) {
        cin >> A[i];
        dp[i][i] = 0;
        rep(j,0,N,1) {
            if (A[i][j] == '1' ) {
                dp[i][j+1] = 1;
                //dp[j+1][i] = 1;
            }
        }
    }
    floyd();
    int cnt = 0;
    rep(i,1,N+1,1) {
        rep(j,1,N+1,1) {
            if (dp[i][j] == -1 && dp[j][i] == -1) ++cnt;
           // cout << dp[i][j] << " " ;
        }
        //cout << "\n";
    }
    cout << cnt/2 << endl; 

    

}