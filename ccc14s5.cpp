#include <bits/stdc++.h>
using namespace std;

#define x first
#define f first
#define y second
#define s second
#define pii pair<int,int>

int n;
const int MAXN = 2005;
pii points[MAXN];
vector<pair<int,pii>> lines;
int mx[MAXN],prevmx[MAXN],dists[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	points[0].x = points[0].y = 0;
	for (int i = 1; i <= n; i++) {
		cin >> points[i].x >> points[i].y;
		for (int j = 0; j < i; j++) {
			lines.push_back({(points[i].x-points[j].x)*(points[i].x-points[j].x)+(points[i].y-points[j].y)*(points[i].y-points[j].y),{j,i}});
		}
	}
	sort(lines.begin(),lines.end());

	for (auto &line : lines) {
		int p1 = line.s.f, p2 = line.s.s, dist = line.f;
		if (dist != dists[p1]) dists[p1] = dist, prevmx[p1] = mx[p1];
		if (dist != dists[p2]) dists[p2] = dist, prevmx[p2] = mx[p2];
		//p2 is never 0
		if (p1 == 0) mx[p1] = max(mx[p1],prevmx[p2]);
		else mx[p1] = max(mx[p1],prevmx[p2]+1), mx[p2] = max(mx[p2],prevmx[p1]+1);
	}
	cout << mx[0] + 1 << "\n";


}