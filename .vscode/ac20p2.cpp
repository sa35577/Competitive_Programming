#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
long long freq[MX];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;
	for (int i = 0,x; i < N; i++) {
		cin >> x;
		freq[x]++;
	}
	int q,val;
	while (Q--) {
		cin >> q >> val;
		if (q == 1) {
			freq[val/2] += freq[val];
			freq[val - (val/2)] += freq[val];
			freq[val] = 0;
		}
		else cout << freq[val] << "\n";
	}
}