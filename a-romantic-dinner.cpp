#include <bits/stdc++.h>
using namespace std;


long long dp[301][101];
//    Time,Units

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long m,u,r;
    cin >> m >> u >> r;
    //m is the time 
    //u is the capacity
    //r is the number of restaurants
    //v is the impression value
    //t is the time
    //f is the restaurant serving
    long long arr[r][3];
    /*
    impression val, time, units
    */

    for (long long i = 0; i < r; i++)
    for (long long j  = 0; j < 3; j++)
        cin >> arr[i][j];
    /*
    dp[m+1][u+1]
    given in time, units
    */
    for (long long i = 0; i < r; i++) {
        for (long long j = m; j >= 0; j--) {
            for (long long k = u; k >= 0; k--) {
                if (j == 0 && k == 0) {
                    dp[j+arr[i][1]][k+arr[i][2]] = max(dp[j+arr[i][1]][k+arr[i][2]],arr[i][0]);
                }
                else if (dp[j][k] > 0 && j + arr[i][1] <= m && k + arr[i][2] <= u) {
                    dp[j+arr[i][1]][k+arr[i][2]] = max(dp[j+arr[i][1]][k+arr[i][2]],arr[i][0] + dp[j][k]);
                }
            }
        }
    }
    long long mx = 0;
    for (long long j = 1 ; j <= m; j++) {
        for (long long k = 1; k <= u; k++) {
            mx = max(mx,dp[j][k]);
        }
    }
    cout << mx;
}




/*

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m,u,r;
    cin >> m >> u >> r;
    //m is the time 
    //u is the capacity
    //r is the number of restaurants
    //v is the impression value
    //t is the time
    //f is the restaurant serving
    int arr[r][3];
    for (int i = 0; i < r; i++)
    for (int j = 0; j < 3; j++) cin >> arr[i][j];
    int dp[m+1][u+1];
    //time,unit
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= u; j++) {
            dp[i][j] = 0;
            for (int k = 0; k < r; k++) {
                if (i >= arr[k][1] && j >= arr[k][2]) {
                    if (j == arr[k][2] || dp[i-arr[k][1]][j-arr[k][2]] > 0) {
                        dp[i][j] = max(dp[i-1][j],dp[i-arr[k][1]][j-arr[k][2]]+arr[k][0]);
                    }
                }
            }
            mx = max(mx,dp[i][j]);
        }
    }
    cout << mx;
}
*/
