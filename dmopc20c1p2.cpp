#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int arr[MAXN],pref[MAXN];

int qsum(int L, int R) {
	return pref[R]-pref[L-1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n,d;
	cin >> n >> d;
	pref[0] = 0;
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pref[i] = pref[i-1]+arr[i];
	}
	int l = 1, r = n,split;
	for (int qq = 0; qq < d; qq++) {
		cin >> split;
		split = split + l-1;
		if (qsum(l,split) >= qsum(split+1,r)) {
			cout << qsum(l,split) << "\n";
			l = split+1;
		}
		else {
			cout << qsum(split+1,r) << "\n";
			r = split;
		}
	}
}