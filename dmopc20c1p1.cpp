#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	for (int idx = 0; idx < n; idx++) {
		cin >> s;
		bool a=0,b=0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'M') a = 1;
			else if (s[i] == 'C') b = 1;
		}
		if (a && b) cout << "NEGATIVE MARKS\n";
		else if (a || b) cout << "FAIL\n";
		else cout << "PASS\n";
	}
}