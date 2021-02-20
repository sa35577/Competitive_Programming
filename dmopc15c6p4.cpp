#include <bits/stdc++.h>
using namespace std;

/*
WHAT IS A MINIMUM SPANNING TREE?
Taken from a huge graph with some number of edges and vertices.
The MST is a set of edges taken such that it connects all the nodes together, this set of edges has the minimum possible sum.
(Total sum of weights is minimized)

There are 2 algorithms used to find the MST:
-Prim's algorithm (uses the simple idea of BFS/DFS and keeps track of the total sum of weights used, the nodes that have been visited already)
--> It is a more basic algorithm, does its job pretty well
--> The efficiency is O((V+E)logV)
--> V is the number of vertices/nodes
--> E is the number of edges

Use a priority queue for the Prim's algorithm.
//priority_queue<pair<dist,node>>

//Check if a node was previously visited
if it has been visited, we break out
if not, we add to the min span tree total, and then after we traverse thru all the edges and add them to the queue.

-Kruskal's algorithm (using a Disjoint Set data structure, sorts edges and inserts them into the DSU if the nodes are not already connected)

--> It is (slightly) more complex, does better than the Prim's algorithm
--> The efficiency is O(ElogV)
--> V is the number of vertices/nodes
--> E is the number of edges

*/


//Kruskal's algorithm

#define ll long long
const int MAXN = 100005;

vector<pair<ll,pair<int,int>>> edges;
int N,K,par[MAXN],subsetRank[MAXN];

int find(int v) {
	if (par[v] == v) return v;
	else return par[v] = find(par[v]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N-1; i++) {
		ll wi;
		cin >> wi;
		edges.push_back({wi,{i,i+1}});
		if (i+K < N) edges.push_back({0,{i,i+K}});
	}
	sort(edges.begin(),edges.end());
	for (int i = 0; i < N; i++) {
		subsetRank[i] = 0;
		par[i] = i;
	}
	ll minSpanDist=0;
	for (pair<ll,pair<int,int>> edge : edges) {
		ll dist = edge.first;
		int n1 = edge.second.first, n2 = edge.second.second;
		int p1 = find(n1), p2 = find(n2); //retrieves both parents of the nodes
		if (p1 != p2) {
			minSpanDist += dist;
			if (subsetRank[p1] > subsetRank[p2]) {
				par[p2] = p1;
			}
			else if (subsetRank[p1] < subsetRank[p2]) {
				par[p1] = p2;
			}
			else {
				par[p2] = p1;
				subsetRank[p1]++;
			}
		} 
	}
	cout << minSpanDist << "\n";
}