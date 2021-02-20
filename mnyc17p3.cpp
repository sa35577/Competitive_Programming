#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MXSIZE = 1e6+5;
const ll MOD = 1e9+7;
ll pows[MXSIZE];



int main() {
	pows[0] = 1LL;
	for (int i = 1; i < MXSIZE; i++) {
		pows[i] = (pows[i-1]*37) % MOD;
	}
	string s1,s2;
	cin >> s1 >> s2;
	ll hash1 = 0, hash2 = 0;
	int ans = 0;
	for (int i = 1; i <= min(s1.size(),s2.size()); i++) {
		hash1 = (hash1 + ((s1[s1.size()-i] - 'A' + 1)*pows[i-1]) % MOD) % MOD;
		hash2 = ((hash2*37)%MOD + (s2[i-1] - 'A' + 1)) % MOD;
		if (hash1 == hash2) {
			ans = i;
		}
		//cout << hash1 << " " << hash2 << "\n";
	}
	//cout << ans << "\n";
	cout << s1.substr(0,s1.size()-ans) + s2;

}