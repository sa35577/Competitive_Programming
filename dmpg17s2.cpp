#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e5+5;
int par[MAXN],N,Q;

int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

int main() {
	scanf("%d%d",&N,&Q);
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	while (Q--) {
		char qType;
		int x,y;
		scanf(" %c%d%d",&qType,&x,&y);
		if (qType == 'A') {
			int px = find(x), py = find(y);
			if (px != py) {
				par[px] = py;
			}
		}
		else {
			if (find(x) == find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
}