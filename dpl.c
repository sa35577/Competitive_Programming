#include <stdio.h>
long long int arr[3005],N,dp[3005][3005];


int main() {
	scanf("%lld",&N);
	for (int i = 1; i <= N; i++) scanf("%lld",&arr[i]),dp[i][i] = arr[i];
	for (int span = 2; span <= N; span++) {
		for (int L = 1; L+span-1 <= N; L++) {
			int R = L+span-1;
			if (arr[L]-dp[L+1][R] > arr[R]-dp[L][R-1]) dp[L][R] = arr[L]-dp[L+1][R];
			else dp[L][R] = arr[R]-dp[L][R-1];
		}
	}
	//left is 1, right is N
	printf("%lld",dp[1][N]);
	return 0;
}