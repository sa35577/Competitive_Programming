#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct DSU {
	int par[MAXN],subsetRank[MAXN],len;
	DSU(int sz) {
		for (int i = 1; i <= sz; i++) {
			par[i] = i;
			subsetRank[i] = 0;
			len = 0;
		}
	}
	int fnd(int x) {
		if (par[x] == x) return x;
		return par[x] = fnd(par[x]);
	}

	void mrg(int x, int y) { //assumes disconnected
		int px = fnd(x), py = fnd(y);
		++len;
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

int N;
#define pii pair<int,int>
pii xp[MAXN], yp[MAXN], zp[MAXN];
vector<pair<int,pii>> xSort,ySort,zSort;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	DSU des(N);
	for (int i = 1; i <= N; i++) {
		cin >> xp[i].first >> yp[i].first >> zp[i].first;
		xp[i].second = yp[i].second = zp[i].second = i;
	}
	sort(xp+1,xp+N+1);
	sort(yp+1,yp+N+1);
	sort(zp+1,zp+N+1);
	xSort.resize(N-1);
	ySort.resize(N-1);
	zSort.resize(N-1);
	for (int i = 2; i <= N; i++) {
		xSort[i-2] = {xp[i].first-xp[i-1].first,{xp[i].second,xp[i-1].second}};
		ySort[i-2] = {yp[i].first-yp[i-1].first,{yp[i].second,yp[i-1].second}};
		zSort[i-2] = {zp[i].first-zp[i-1].first,{zp[i].second,zp[i-1].second}};
	}
	sort(xSort.begin(),xSort.end());
	sort(ySort.begin(),ySort.end());
	sort(zSort.begin(),zSort.end());
	long long ans = 0;
	int x = 0, y = 0, z = 0;
	while (des.len < N-1) {
		while (des.ctd(xSort[x].second.first,xSort[x].second.second) && x < N-1) x++;
		while (des.ctd(ySort[y].second.first,ySort[y].second.second) && y < N-1) y++;
		while (des.ctd(zSort[z].second.first,zSort[z].second.second) && z < N-1) z++;
		if (x < N-1) {
			if (y < N-1) {
				if (z < N-1) {
					//xyz
					int mn = min(xSort[x].first,min(ySort[y].first,zSort[z].first));
					if (mn == xSort[x].first) {
						des.mrg(xSort[x].second.first,xSort[x].second.second);
						ans += xSort[x].first;
					}
					else if (mn == ySort[y].first) {
						des.mrg(ySort[y].second.first,ySort[y].second.second);
						ans += ySort[y].first;
					}
					else if (mn == zSort[z].first) {
						des.mrg(zSort[z].second.first,zSort[z].second.second);
						ans += zSort[z].first;
					}
				}
				else {
					//xy
					if (xSort[x].first < ySort[y].first) {
						des.mrg(xSort[x].second.first,xSort[x].second.second);
						ans += xSort[x].first;		
					}
					else {
						des.mrg(ySort[y].second.first,ySort[y].second.second);
						ans += ySort[y].first;
					}
				}
			}
			else {
				if (z < N-1) {
					//xz
					if (xSort[x].first < zSort[z].first) {
						des.mrg(xSort[x].second.first,xSort[x].second.second);
						ans += xSort[x].first;		
					}
					else {
						des.mrg(zSort[z].second.first,zSort[z].second.second);
						ans += zSort[z].first;
					}
				}
				else {
					//x	
					des.mrg(xSort[x].second.first,xSort[x].second.second);
					ans += xSort[x].first;				
				}
			}
		}
		else {
			if (y < N-1) {
				if (z < N-1) {
					//yz
					if (ySort[y].first < zSort[z].first) {
						des.mrg(ySort[y].second.first,ySort[y].second.second);
						ans += ySort[y].first;
					}
					else {
						des.mrg(zSort[z].second.first,zSort[z].second.second);
						ans += zSort[z].first;
					}
				}
				else {
					//y
					des.mrg(ySort[y].second.first,ySort[y].second.second);
					ans += ySort[y].first;
				}
			}
			else {
				if (z < N-1) {
					//z
					des.mrg(zSort[z].second.first,zSort[z].second.second);
					ans += zSort[z].first;
				}
				else {
					//shoot			
				}
			}
		}
	}
	cout << ans << "\n";
}