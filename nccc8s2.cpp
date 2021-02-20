#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	long long freq[26];
	fill(freq,freq+26,1LL);
	for (int i = 0; i < s.size(); i++) {
		freq[s[i]-'a']++;
	}
	long long prod = 1;
	for (int i = 0; i < 26; i++) {
		prod = (prod * freq[i]) % MOD;
	}
	cout << prod << "\n";

}