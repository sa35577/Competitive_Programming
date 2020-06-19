#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
int a[maxn];
int n;
int dp[maxn][maxn];

int calc(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ret;
    if ((r+l) % 2 != n % 2) ret = max(calc(l+1,r)+a[l],calc(l,r-1)+a[r]);
    else ret = min(calc(l+1,r)-a[l],calc(l,r-1)-a[r]);
    dp[l][r] = ret;
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << calc(1,n);

}