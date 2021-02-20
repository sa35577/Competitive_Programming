#include <bits/stdc++.h>
using namespace std;

pair<int,int> freq[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 1000; i++) freq[i] = {0,i};
	int N;
	cin >> N;
	while (N--) {
		int x;
		cin >> x;
		freq[--x].first++;
	}
	sort(freq,freq+1000);
	int R = 999, L = 999;
	while (freq[L-1].first == freq[R].first && L >= 0) L--;
	if (L != R) {
		cout << freq[R].second - freq[L].second;
		return 0;
	}
	int r = L-1, l = L-1;
	while (freq[l-1].first == freq[r].first && l >= 0) l--;
	int a1 = abs(freq[l].second-freq[R].second);
	int a2 = abs(freq[r].second-freq[R].second);
	int a3 = abs(freq[l].second-freq[L].second);
	int a4 = abs(freq[r].second-freq[L].second);
	cout << max(max(a1,a2),max(a3,a4));
	return 0;
}