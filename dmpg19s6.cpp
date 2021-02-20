#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int arr[MAXN],psa[MAXN],lastOne[MAXN],nextOne[MAXN];

int main() {
	int N;
	int Q;
	int l,r,x;
	scanf("%d%d",&N,&Q);
	lastOne[0] = nextOne[N+1] = -1;
	for (int i = 1; i <= N; i++) {
		scanf("%d",&arr[i]);
		psa[i] = psa[i-1]+arr[i];
		lastOne[i] = lastOne[i-1];
		if (arr[i] == 1) lastOne[i] = i;
	}
	for (int i = N; i >= 1; i--) {
		nextOne[i] = nextOne[i+1];
		if (arr[i] == 1) nextOne[i] = i;
	}	
	while (Q--) {
		scanf("%d%d%d",&l,&r,&x);
		int sum = psa[r]-psa[l-1];
		if (x > sum) printf("NO\n");
		else {
			if (sum == x) printf("YES\n");
			else if (sum % 2 == x % 2) printf("YES\n");
			else if (nextOne[l] > 0 && psa[r]-psa[nextOne[l]] >= x) {
				printf("YES\n");
			}
			else if (lastOne[r] > 0 && psa[lastOne[r]-1]-psa[l-1] >= x) {
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
}