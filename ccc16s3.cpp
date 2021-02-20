#include <bits/stdc++.h>
using namespace std;

int N,M;
const int MAX = 100005;
vector<int> graph[MAX];
int dists[MAX];
bitset<MAX> pho;
int last;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0,x; i < M; i++) {
		cin >> x;
		pho[x] = true;
		last = x;
	}
	for (int i = 0,a,b; i < N-1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	deque<int> points;
	for (int i = 0; i < N; i++) {
		if (graph[i].size() == 1 && !pho[i]) points.push_back(i);
	}
	while (!points.empty()) {
		int cur = points.front();
		points.pop_front();
		for (int nxt : graph[cur]) {
			int idx = 0;
			while (graph[nxt][idx] != cur) ++idx;
			graph[nxt].erase(graph[nxt].begin()+idx);
			if (graph[nxt].size() == 1 && !pho[nxt]) {
				points.push_back(nxt);
			}
		}
		graph[cur].clear();
	}
	for (int i = 0; i < N; i++) dists[i] = 9999999;
	dists[last] = 0;
	points.push_back(last);
	while (!points.empty()) {
		int cur = points.front();
		points.pop_front();
		for (int nxt : graph[cur]) {
			if (dists[nxt] > dists[cur] + 1) {
				dists[nxt] = dists[cur] + 1;
				points.push_back(nxt);
			}
		} 
	}
	last = -1;
	int mx = -1;
	for (int i = 0; i < N; i++) {
		if (dists[i] == 9999999);
		else if (mx < dists[i]) mx = dists[i],last = i;
	} 
	for (int i = 0; i < N; i++) dists[i] = 9999999;
	dists[last] = 0;
	points.push_back(last);
	while (!points.empty()) {
		int cur = points.front();
		points.pop_front();
		for (int nxt : graph[cur]) {
			if (dists[nxt] > dists[cur] + 1) {
				dists[nxt] = dists[cur] + 1;
				points.push_back(nxt);
			}
		} 
	}
	mx = -1;
	int high = 0;
	for (int i = 0; i < N; i++) {
		if (dists[i] != 9999999) {
			mx = max(mx,dists[i]);
		}
		else high++;
	}
	cout << 2*(N-high-1)-mx;
}