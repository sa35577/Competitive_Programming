#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
long long dp[MX];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 0;
	fill(dp+1,dp+MX,INT_MAX);
	int x,n;
	cin >> x >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) cin >> coins[i];
	for (int i = 1; i <= x; i++) {
		for (int j : coins) {
			if (i-j >= 0) {
				dp[i] = min(dp[i],dp[i-j]+1);
			}
		}
	}
	cout << dp[x] << "\n";

}