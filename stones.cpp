#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,k;
    cin >> n >> k;
    ll A[100];
    for (int i = 0; i < n; i++) cin >> A[i];
    bool dp[100005];
    fill(dp,dp+100005,false);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j] <= i) {
                dp[i] = (dp[i] | !dp[i-A[j]]);
            }
        }
    }
    if (dp[k]) cout << "First\n";
    else cout << "Second\n"; 

}