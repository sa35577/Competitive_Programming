#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ll long long


int n;
const int MAXN = 200005;

struct Node {
	vector<int> output = vector<int>();
	vector<int> input = vector<int>();
	ll pop=0;
	ll income = 0;
	ll outreach = 0;
} graph[MAXN];

pii edges[MAXN];
vector<int> startIncome, startOutreach;
bitset<MAXN> vis;
int calc[MAXN];

int dfsIncome(int v) {
	if (calc[v] != -1) return calc[v];
	for (int nxt : graph[v].input) {
		graph[v].income += dfsIncome(nxt);
	}
	return calc[v] = graph[v].income + graph[v].pop;
}

int dfsOutreach(int v) {
	if (calc[v] != -1) return calc[v];
	for (int nxt : graph[v].output) {
		graph[v].outreach += dfsOutreach(nxt);
	}

	return calc[v] = graph[v].outreach + graph[v].pop;
}



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> graph[i].pop;
	}
	int a,b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[i].first=a;
		edges[i].second=b;
		graph[a].output.emplace_back(b);
		graph[b].input.emplace_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (graph[i].output.size() == 0) startIncome.emplace_back(i);
		if (graph[i].input.size() == 0) startOutreach.emplace_back(i);
	}
	for (int i = 1; i <= n; i++) calc[i] = -1;
	for (int i : startIncome) {
		dfsIncome(i);
	}
	for (int i = 1; i <= n; i++) calc[i] = -1;
	for (int i : startOutreach) {
		dfsOutreach(i);
	}
	ll score = 0, addOn = 0;
	for (int i = 1; i <= n; i++) {
		score += graph[i].pop * (graph[i].pop-1 + graph[i].outreach);
		//cout << graph[i].pop << " " << graph[i].outreach << " " << graph[i].income << endl;
	}
	//making bidirectional and checking increase
	for (int i = 1; i < n; i++) {
		int s = edges[i].first, f = edges[i].second;
		ll a1,a2;
		a1 = graph[s].pop+graph[s].outreach-graph[f].pop-graph[f].outreach;
		a2 = graph[f].pop+graph[f].income-graph[s].pop-graph[s].income;
		addOn = max(addOn,a1*a2);
	}
	//cout << score << " " << addOn << endl;
	cout << addOn+score << endl;
}