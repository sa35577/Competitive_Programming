#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;
string config;
int N,K;

vector<pair<int,ll>> ac;
vector<pair<ll,ll>> wa;


ll choose3(ll n) {
	if (n <= 2) return 0;
	ll res = n*(n-1)*(n-2);
	return res/6;
}

ll choose2(ll n) {
	if (n <= 1) return 0;
	ll res = n*(n-1);
	return res/2;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K >> config;
	ll numC = 0,numA=0,numW=0,totac=0;

	for (int i = config.size(); i >= 0; i--) {
		if (config[i] == 'C') numC++;
		else if (config[i] == 'A') {
			numA++;
			//ac.push_back({i,numC});
			totac += numC;
		}
		else if (config[i] == 'W') {
			numW++;
			wa.push_back({numA,totac});
		}
	}
	if (numA == 0 || numC == 0 || numW == 0) {
		printf("0\n");
		return 0;
	}
	ll res = 0;
	ll kc3 = choose3(K) % MOD, kc2 = choose2(K) % MOD;
	for (pair<ll,ll> cur : wa) {
		res += ((kc2*totac) % MOD + (numC*numA*kc3) % MOD + (numC*cur.first*kc2) % MOD + (cur.second*K) % MOD) % MOD;
		res %= MOD;
	}
	cout << res << "\n";
	return 0;

}