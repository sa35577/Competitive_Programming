#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	fill(dp,dp+1001,0);
	int C,M;
	cin >> C >> M;
	int ni,ki,mx = -1;
	while (C--) {
		cin >> ni >> ki;
		for (int i = M; i >= ki; i--) {
			dp[i] =  max(dp[i],dp[i-ki]+ni);
			mx = max(mx,dp[i]);
		}
	}
	cout << mx;
}