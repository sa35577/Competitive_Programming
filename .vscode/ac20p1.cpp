#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a,b,c;
		cin >> a >> b >> c;
		if (a > b) swap(a,b);
		if (b > c) swap(b,c);
		if (a > b) swap(a,b);
		if (a*a + b*b == c*c) cout << "R\n";
		else if (a*a + b*b > c*c) cout << "A\n";
		else cout << "O\n";
	}
}