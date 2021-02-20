#include <bits/stdc++.h>
using namespace std;


const int MX = 55;
bool vis[MX];
vector<int> graph[MX];
pair<int,int> edges[MX*MX-MX];
int N,M;

bool bfs(pair<int,int> notAllowed) {
	deque<int> deck;
	deck.push_back(1);
	fill(vis,vis+MX,false);
	vis[1] = 1;
	while (!deck.empty()) {
		int cur = deck.front();
		deck.pop_front();
		for (int nxt : graph[cur]) {
			if (!(vis[nxt] || (cur == notAllowed.first && nxt == notAllowed.second))) deck.push_back(nxt),vis[nxt] = 1;
			
		}
		if (vis[N]) return true;
	}
	return vis[N];

}

int main() {
	scanf("%d%d",&N,&M);
	for (int i = 0,a,b; i < M; i++) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		edges[i] = {a,b};
	}
	for (int i = 0; i < M; i++) {
		if (bfs(edges[i])) printf("YES\n");
		else printf("NO\n");
	}
}