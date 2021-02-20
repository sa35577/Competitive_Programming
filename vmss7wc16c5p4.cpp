#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> dp(2*n+1);
    for (int i = 0; i <= n; i++) dp[i] = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] != 0 || i == 0) {
            dp[i+a] = max(dp[i+a],dp[i]+1);
            dp[i+b] = max(dp[i+b],dp[i]+1);
            dp[i+c] = max(dp[i+c],dp[i]+1);
        }
    }
    cout << dp[n];
}