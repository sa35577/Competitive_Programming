#include <bits/stdc++.h>
using namespace std;

set<int> os;
set<int>::iterator it;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int G,P;
	cin >> G >> P;
	for (int i = 1; i <= G; i++) os.insert(i);
	for (int i = 1,x; i <= P; i++) {
		cin >> x;
		it = os.lower_bound(x);
		if (it == os.begin() && *it != x) {
			cout << i-1 << "\n";
			return 0;
		}
		if (*it != x) it--;
		os.erase(it);
	}
	cout << P << "\n";

}