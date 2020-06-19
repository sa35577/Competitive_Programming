#include <bits/stdc++.h>
using namespace std;

int n,k;
const int maxn = 105;
int a[maxn];
const int MOD = 1000000007;
int dp[maxn][100005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=k; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            if (j-a[i]-1 >= 0) {
                dp[i][j] = (dp[i][j]-dp[i-1][j-a[i]-1]+MOD)%MOD;
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;


    
}