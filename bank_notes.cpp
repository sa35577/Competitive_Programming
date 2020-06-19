#include <bits/stdc++.h>
using namespace std;

int arr[20005];
int quan[20005];
int dp[205][20005];
int main() {
    int n,k;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> quan[i];
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i = n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        
    }



    
}