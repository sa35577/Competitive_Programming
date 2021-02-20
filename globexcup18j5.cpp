#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5+5;
const ll inf = 1000000000000LL;
ll dist[MAXN];
vector<int> graph[MAXN];

int main() {
	fill(dist,dist+MAXN,inf);
	int N,M,Q,C;
	scanf("%d%d%d%d",&N,&M,&Q,&C);
	for (int i = 0,u,v; i < M; i++) {
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,C});
	dist[C] = 0;
	while (!pq.empty()) {
		int curDist = pq.top().first, curNode = pq.top().second;
		pq.pop();
		if (curDist <= dist[curNode]) {
			for (int nxt : graph[curNode]) {
				if (dist[nxt] > dist[curNode] + 1) {
					dist[nxt] = dist[curNode] + 1;
					pq.push({dist[nxt],nxt});
				}
			}
		}
	}
	for (int i = 0,p,q; i < Q; i++) {
		scanf("%d%d",&p,&q);
		if (dist[p] == inf || dist[q] == inf) {
			printf("This is a scam!\n");
		}
		else {
			printf("%lld\n",dist[p]+dist[q]);
		}
	}
}