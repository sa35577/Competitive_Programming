#include <bits/stdc++.h>
using namespace std;


bitset<1000005> used;
struct DSU {
	int par[100005],subsetRank[100005],len;
	DSU(int sz) {
		for (int i = 1; i <= sz; i++) {
			par[i] = i;
			subsetRank[i] = 0;
			len = 0;
		}
	}
	int fnd(int x) {
		if (par[x] == x) return x;
		return par[x] = fnd(par[x]);
	}

	void mrg(int x, int y, int i) { //assumes disconnected
		int px = fnd(x), py = fnd(y);
		used[i] = 1;
		++len;
		if (subsetRank[px] > subsetRank[py]) {
			par[py] = px;
		}
		else if (subsetRank[px] < subsetRank[py]) {
			par[px] = py;
		}
		else {
			par[py] = px;
			subsetRank[px]++;
		}
	}

	bool ctd(int x, int y) {
		return fnd(x) == fnd(y);
	}
};

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	DSU des(N);
	for (int i = 1,u,v; i <= M; i++) {
		scanf("%d%d",&u,&v);
		if (!des.ctd(u,v)) {
			des.mrg(u,v,i);
		}
	}
	if (des.len != N-1) printf("Disconnected Graph\n");
	else {
		for (int i = 1; i <= M; i++) if (used[i]) printf("%d\n",i);
	}
}