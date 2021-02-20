#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;
unordered_set<string>::iterator it;
vector<string> v;

int main() {
	string a,b;
	cin >> a >> b;
	//adding
	for (int aa = 0; aa < a.size(); aa++) {
		for (int bb = 0; bb <= b.size(); bb++) {
			s.insert(b.substr(0,bb) + a[aa] + b.substr(bb));
		}
	}

	//changing
	for (int aa = 0; aa < a.size(); aa++) {
		for (int bb = 0; bb < b.size(); bb++) {
			if (a[aa] != b[bb]) {
				s.insert(b.substr(0,bb)+a[aa]+b.substr(bb+1));
			}
		}
	}
	//removing
	for (int aa = 0; aa < a.size(); aa++) {
		for (int bb = 0; bb < b.size(); bb++) {
			if (a[aa] == b[bb]) {
				s.insert(b.substr(0,bb)+b.substr(bb+1));
			}
		}
	}
	//sorting
	for (it = s.begin(); it != s.end(); it++) {
		v.push_back(*it);
	}
	sort(v.begin(),v.end());
	for (string n : v) cout << n << "\n";
}