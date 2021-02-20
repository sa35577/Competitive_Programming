#include <bits/stdc++.h>
using namespace std;

//aeiouy
//0, 4, 8, 14, 20, 24

bool isVowel(char c) {
	if (c-'a'==0) return true;
	if (c-'e'==0) return true;
	if (c-'i'==0) return true;
	if (c-'o'==0) return true;
	if (c-'u'==0) return true;
	if (c-'y'==0) return true;
	return false;
}

bool isConsonant(char c) {
	if (c-'y'==0) return true;
	return !isVowel(c);
}

int main() {
	int n,c,v;
	string s;
	cin >> n >> c >> v;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i <= min(n-1,c); i++) if (isConsonant(s[i])) ++cnt;
	if (cnt == c+1) {
		cout << "NO\n";
		return 0;
	}
	for (int i = c+1; i < n; i++) {
		if (isConsonant(s[i])) ++cnt;
		if (isConsonant(s[i-(c+1)])) --cnt;
		if (cnt == c+1) {
			cout << "NO\n";
			return 0;
		}
	}

	cnt = 0;
	for (int i = 0; i <= min(n-1,v); i++) if (isVowel(s[i])) ++cnt;
	if (cnt == v+1) {
		cout << "NO\n";
		return 0;
	}
	for (int i = v+1; i < n; i++) {
		if (isVowel(s[i])) ++cnt;
		if (isVowel(s[i-(v+1)])) --cnt;
		if (cnt == v+1) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

}