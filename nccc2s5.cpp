#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005,MAXM=5005;
vector<pair<int,int>> minSpanGraph[MAXN];
vector<pair<int,pair<int,int>>> v;
pair<int,pair<int,int>> edges[MAXM];
int N,M;

struct DSU {
	int par[MAXN],subsetRank[MAXN];
	DSU(int sz) {
		for (int i = 1; i <= sz; i++) {
			par[i] = i;
			subsetRank[i] = 0;
		}
	}
	int fnd(int x) {
		if (par[x] == x) return x;
		return par[x] = fnd(par[x]);
	}

	void mrg(int x, int y) {
		int px = fnd(x), py = fnd(y);
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
		if (edges[i].second.second > edges[i].second.first) swap(edges[i].second.second,edges[i].second.first);
		v.push_back(edges[i]);
	}
	sort(v.begin(),v.end(),greater<pair<int,pair<int,int>>>());
	int Q;
	cin >> Q;
	int ai,bi,wi,mi,xi,op;
	DSU des(N);
	for (pair<int,pair<int,int>> edge : v) {
		int len = edge.first, n1 = edge.second.first, n2 = edge.second.second;
		if (!des.ctd(n1,n2)) {
			minSpanGraph[n1].push_back({len,n2});
			minSpanGraph[n2].push_back({len,n1});
			des.mrg(n1,n2);
		}
	}
	/*for (int i = 1; i <= N; i++) {
		for (auto j : minSpanGraph[i]) cout << j.second << " ";
		cout << "\n";
	}*/
	while (Q--) {
		cin >> op;
		if (op == 1) {
			cin >> mi >> xi;
			for (int i = 1; i <= N; i++) minSpanGraph[i].clear();
			remove(v.begin(),v.end(),edges[mi]);
			edges[mi].first = xi;
			int j = 0;
			while (j < v.size() && v[j] > edges[mi]) j++;
			v.insert(v.begin()+j,edges[mi]);
			des = DSU(N);
			for (pair<int,pair<int,int>> edge : v) {
				int len = edge.first, n1 = edge.second.first, n2 = edge.second.second;
				if (!des.ctd(n1,n2)) {
					minSpanGraph[n1].push_back({len,n2});
					minSpanGraph[n2].push_back({len,n1});
					des.mrg(n1,n2);
				}
			}
		}
		else if (op == 2) {
			cin >> ai >> bi >> wi;
			deque<int> deck;
			bitset<MAXN> vis;
			vis[ai] = 1;
			deck.push_back(ai);
			while (!deck.empty() && !vis[bi]) {
				int cur = deck.front();
				deck.pop_front();
				for (pair<int,int> nxt : minSpanGraph[cur]) {
					if (nxt.first >= wi && !vis[nxt.second]) {
						vis[nxt.second] = 1;
						deck.push_back(nxt.second);
					}
				}
			} 
			cout << vis[bi] << "\n";
		}
	}

}