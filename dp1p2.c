#include <stdio.h>


int arr[1005],dp[1005][1005];

inline int min(int a, int b) {
    if (a < b) return a;
    return b;
}

inline int max(int a, int b) {
    if (a > b) return a;
    return b;
}

inline int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
	int sum = 0;
	int N;
	scanf("%d",&N);
	int prod = (N % 2 == 0 ? -1 : 1);
	for (int i = 1; i <= N; i++) scanf("%d",&arr[i]),dp[i][i] = prod*arr[i],sum += arr[i];
	for (int span = 2; span <= N; span++) {
		prod = -prod;
		for (int L = 1; L+span-1 <= N; L++) {
			int R = L+span-1;
			if (prod == 1) {
				//my turn
				dp[L][R] = max(arr[L]+dp[L+1][R],dp[L][R-1]+arr[R]);
			}
			else {
				//friend turn
				dp[L][R] = min(-arr[L]+dp[L+1][R],dp[L][R-1]-arr[R]);
			}
		}
	}
	int ans;
	ans = dp[1][N] + (sum-abs(dp[1][N]))/2;
	printf("%d\n",ans);
}