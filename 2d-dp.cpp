#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,sm = 0;
    cin >> n;
    int arr[101];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sm += arr[i];
    }
    int dp[105][sm+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= sm; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sm; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
        }
    }
    int mn = 50000;
    for (int a = sm/2; a >= 0; a--) {
        if (dp[n][a] == 1) {
            mn = sm-2*a; break;
        }
        
    }
    cout << mn;

    
}