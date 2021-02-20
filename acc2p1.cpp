#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
#define ll long long

ll dist[MAXN][MAXN][MAXN];
int adj[MAXN][MAXN];
int N;

void floyd(int v) {
	dist[1][v][v] = 0;
	priority_queue<pair<ll,int>, 
	vector<pair<ll,int>>,
	greater<pair<ll,int>>> pq;
	pq.push({0,v});
	while (!pq.empty()) {
		ll curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (curDist > dist[1][v][curNode]) continue;
		for (int i = 1; i <= N; i++) {
			if (adj[curNode][i] && dist[1][v][i] > dist[1][v][curNode] + adj[curNode][i]) {
				dist[1][v][i] = dist[1][v][curNode] + adj[curNode][i];
				pq.push({dist[1][v][i],i});
			}
		}
	}
}

int main() {
	for (int i = 0; i < MAXN; i++)
	for (int j = 0; j < MAXN; j++)
	for (int k = 0; k < MAXN; k++)
		dist[i][j][k] = 10000000000000LL;
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) 
	for (int j = 1; j <= N; j++) {
		scanf("%d",&adj[i][j]);
	}
	for (int i = 1; i <= N; i++) floyd(i);
	for (int d = 2; d <= N; d++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					dist[d][i][j] = min(dist[d][i][j],max(dist[d-1][i][k],dist[1][k][j]));
				}
			}
		}
	}
	int Q,a,b,d;
	scanf("%d",&Q);
	while (Q--) {
		scanf("%d%d%d",&a,&b,&d);
		if (dist[d][a][b] == 10000000000000LL) printf("0\n");
		else printf("%lld\n",dist[d][a][b]);
	}

	
}