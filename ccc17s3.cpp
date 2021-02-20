#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MX = 2005;
ll lengths[MX], sums[MX<<1];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0, len; i < n; i++) {
		cin >> len;
		lengths[len]++;
	}
	for (int i = 0; i <= 2000; i++) {
		for (int j = i; j <= 2000; j++) {
			if (lengths[i] && lengths[j]) {
				if (i == j) sums[i+j] += lengths[i]>>1;
				else sums[i+j] += min(lengths[i],lengths[j]);
			}
		}
	}
	ll ans = -1, cnt = -1;
	for (int i = 1; i <= 4000; i++) {
		if (sums[i] > ans) {
			ans = sums[i];
			cnt = 1;
		}
		else if (sums[i] == ans) ++cnt;
	}
	cout << ans << " " << cnt << "\n";
}