#include <bits/stdc++.h>
using namespace std;

#define inf 100000000
int n,m;
const int MAXN = 100005;
int arr[MAXN];
const int MAXCOLOURS = 1000005;
int fl[MAXCOLOURS][2];
int ans = 0;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < MAXCOLOURS; i++) {
		fl[i][0] = inf;
		fl[i][1] = -inf;
	}
	for (int i = 0; i < n; i++) {
		fl[arr[i]][0] = min(fl[arr[i]][0],i);
		fl[arr[i]][1] = max(fl[arr[i]][1],i);
	}
	int f,l;
	for (int i = 0; i < m; i++) {
		cin >> f >> l;
		if (fl[f][0] != inf && fl[l][1] != -inf && fl[l][1] >= fl[f][0]) {
			ans = max(ans,fl[l][1]-fl[f][0]+1);
		}
	}
	cout << ans << endl;
}