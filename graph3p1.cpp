#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30005;
vector<int> graph[MAXN];
int N,M,K;
deque<pair<int,int>> deck;
bitset<MAXN> vis;

int main() {
	scanf("%d%d",&N,&M);
	int a,b;
	while (M--) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	scanf("%d",&K);
	while (K--) {
		scanf("%d",&a);
		deck.push_back({a,0});
		vis[a] = 1;
	}
	int v,dist;
	while (!deck.empty()) {
		v = deck.front().first, dist = deck.front().second;
		deck.pop_front();
		for (int nxt : graph[v]) {
			if (!vis[nxt]) {
				vis[nxt]=1;
				deck.push_back({nxt,dist+1});
			}
		}
	}
	printf("%d\n",dist);
}