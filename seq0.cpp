#include <bits/stdc++.h>
using namespace std;

int N;
const int MAXN = 1e6+5;
long long arr[MAXN],dp[MAXN];

int main() {
	arr[0] = dp[0] = 0LL;
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld",&arr[i]);
		if (i == 1) dp[i] = max(arr[i],dp[0]);
		else dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
	}
	printf("%lld\n",dp[N]);
}