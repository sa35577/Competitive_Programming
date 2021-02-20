#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 100005;
const ll MOD = 1000000007;
int arr[MAXN],N;
ll dp[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = 0;
	}
	int prevMax = -1,idx=-1;
	ll sumdp=dp[0];
	for (int i = 1; i <= N; i++) {
		if (arr[i] > prevMax) {
			dp[i] = sumdp % MOD;
			prevMax = arr[i];
			idx = i;
		}
		else if (arr[i] < prevMax) {
			dp[i] = dp[idx] % MOD;
		}
		else {
			dp[i] = (dp[idx] * (i - idx + 1)) % MOD;
			idx = i;
		}
		sumdp += dp[i];
		sumdp %= MOD;
	}
	cout << dp[N];

}