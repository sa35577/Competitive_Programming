#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int nxt[MAXN][26];
int firstOccur[26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int slen,tlen;
	cin >> slen >> tlen;
	string s,t;
	cin >> s >> t;
	s += '0';
	for (int i = 0; i < 26; i++) {
		firstOccur[i] = -1;
		for (int j = 0; j < MAXN; j++) {
			nxt[j][i] = -1;
		}
	}
	for (int i = slen-1; i >= 0; i--) {
		firstOccur[s[i]-'a'] = i;
		for (int j = 0; j < 26; j++) {
			if (s[i+1] - 'a' == j) {
				nxt[i][j] = i+1;
			}
			else nxt[i][j] = nxt[i+1][j];
		}
	}
	int idx = 0,cnt = 1,loc=0;
	while (idx < tlen) {
		int req = t[idx]-'a';
		if (firstOccur[req] == -1) {
			cout << -1 << "\n";
			return 0;
		}
		if (s[loc]-'a' == req) {
			idx++;
			//if (idx == tlen) break;
			loc++;
			
		}
		else if (nxt[loc][req] != -1) {
			idx++;
			//if (idx == tlen) break;
			loc = nxt[loc][req]+1;
		}
		else if (nxt[loc][req] == -1 || loc >= slen) {
			loc = 0;
			cnt++;
		}
	}
	long long n1 = cnt, n2 = slen, n3 = slen-loc;
	long long res = n1*n2-n3;
	cout << res << "\n";
}