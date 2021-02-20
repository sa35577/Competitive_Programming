#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pib pair<int,bool>
#define f first
#define s second
const int MX = 1e5+5;
vector<int> graph[MX];
struct DisjointSet {
	int par[MX],size;
	DisjointSet(int sz) {
		size = sz;
		for (int i = 0; i < sz+1; i++) par[i] = i;
	}
	int root(int x) {
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}
	void unite(int x1, int x2) {
		int p1 = root(x1), p2 = root(x2);
		if (p1 == p2) return;
		if (x1 < x2) {
			par[p2] = p1;
			root(x2);
		}
		else {
			par[p1] = p2;
			root(x1);
		}
		
	}
	bool sameParent(int x1, int x2) {
		return root(x1) == root(x2);
	}
};

ll dist1[MX], dist2[MX];

int main() {
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	DisjointSet des(n);
	for (int mm = 0,va,vb; mm < m; mm++) {
		scanf("%d%d",&va,&vb);
		graph[va].push_back(vb);
		graph[vb].push_back(va);
		des.unite(va,vb);

	}
	for (int query = 0,va,vb; query < q; query++) {
		scanf("%d%d",&va,&vb);
		int common=-1;
		if (va == vb) printf("0\n");
		else if (!des.sameParent(va,vb)) printf("-1\n");
		else {
			queue<pib> qq; //0 from va, 1 from vb
			memset(dist1,-1,sizeof(dist1));
			memset(dist2,-1,sizeof(dist2));
			dist1[va] = 0, dist2[vb] = 0;
			qq.push({va,0});
			qq.push({vb,1});
			
			while (!qq.empty()) {
				pib cur = qq.front();
				qq.pop();
				bool flag = 0;
				for (int v : graph[cur.f]) {
					if (cur.s && dist2[v] != -1) continue;
					else if (!cur.s && dist1[v] != -1) continue;

					if (cur.s) {
						dist2[v] = dist2[cur.f]+1;
						if (dist1[v] != -1) {
							flag = 1;
							common = v;
							break;
						}
					}
					else {
						dist1[v] = dist1[cur.f]+1;
						if (dist2[v] != -1) {
							flag = 1;
							common = v;
							break;
						}
					}
					qq.push({v,cur.s});
				}
				if (flag) break;
			}
			
			if (common > 0) {
				printf("%lld\n",dist1[common]+dist2[common]);
			}
			else printf("-1\n");
			
		}
		
	}
	


}