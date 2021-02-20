#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
string config;
int N,M,K;

struct DSU {
	int par[MAXN]; //the parent of each node is stored in its index
	int subsetRank[MAXN];
	DSU(int size) {
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			subsetRank[i] = 0;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	bool ctd(int x, int y) {
		return find(x) == find(y);
	}
	void mrg(int x, int y) {
		int px = find(x), py = find(y);
		if (px == py) return;
		if (subsetRank[px] > subsetRank[py]) par[py] = px;
		else if (subsetRank[px] < subsetRank[py]) par[px] = py;
		else {
			par[py] = px;
			subsetRank[px]++;
		}
	}
};



int main() {
	scanf("%d%d",&N,&M);
	DSU dsu(N);
	for (int i = 0,f,cur; i < M; i++) {
		scanf("%d%d",&K,&f);
		for (int j = 1; j < K; j++) {
			scanf("%d",&cur);
			dsu.mrg(f,cur);
		}
	}
	int tot = 1;
	for (int i = 2; i <= N; i++) if (dsu.ctd(1,i)) ++tot;
	printf("%d\n",tot);
	printf("1");
	for (int i = 2; i <= N; i++) if (dsu.ctd(1,i)) printf(" %d",i);
	
}