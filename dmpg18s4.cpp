#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int parent[MAXN],sz[MAXN],arr[MAXN],N;

int find(int x) {
	if (parent[x] == x) return x;
	return find(parent[x]);
}

int main() {
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		scanf("%d",&arr[i]);
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 1,u,v; i < N; i++) {
		scanf("%d%d",&u,&v);
		if ((arr[u]+arr[v])% 2 == 1) { //different in parity
			int pu = find(u), pv = find(v);
			if (pu != pv) {
				parent[pu] = pv;
				sz[pv] += sz[pu];
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] % 2 == 1) ans += (long long) sz[find(i)];
	}
	printf("%lld\n",ans);
}