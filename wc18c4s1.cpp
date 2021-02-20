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
	scanf("%d%d%d",&N,&M,&K);
	cin >> config;
	config = " " + config;
	DSU dsu(N);
	for (int i = 0; i < M; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (config[x] == config[y])
			dsu.mrg(x,y);
	}
	int tot = 0;
	for (int i = 0,u,v; i < K; i++) {
		scanf("%d%d",&u,&v);
		if (dsu.ctd(u,v)) tot++;
	}
	printf("%d\n",tot);
}