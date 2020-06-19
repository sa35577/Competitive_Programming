#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,v;
    cin >> n >> v;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int dp[10000][10001];
    for (int i = 0; i < n; i++) {
        
        dp[i][0] = 0;
        for (int j = 1; j < 10001; j++) dp[i][j] = INT_MAX;
        for (int j = 0; j < 10001; j++) {
            if (dp[i][j]   < INT_MAX) {
                for (int k = 0; k <= i; k++) {
                    if (j + arr[k] <= 10000) {
                        dp[i][j+arr[k]] = min(dp[i][j+arr[k]],dp[i][j]+1);
                    }
                }
            }
        }   
    }
    int c,l;
    for (int i = 0; i < v; i++) {
        cin >> c >> l;
        l--;
        if (dp[l][c] == INT_MAX) cout << -1 << "\n";
        else cout << dp[l][c] << "\n";
    }
    
    

}