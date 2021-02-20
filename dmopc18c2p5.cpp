#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll> 

ll N;
int M,K;
const ll MOD = 1000000007LL;
vll sums,res;

void matrixSquare() {
	//squares sums matrix
	vll ans(sums.size());
	for (int i = 0; i < sums.size(); i++)
	for (int j = 0; j < sums.size(); j++) {
		if (i+j < ans.size()) {
			ans[i+j] = (ans[i+j] + sums[i]*sums[j]) % MOD;
		}
	} 
	sums = ans;
}

void matrixMult() {
	//multiply res matrix by sums matrix
	vll ans(sums.size());
	for (int i = 0; i < sums.size(); i++)
	for (int j = 0; j < res.size(); j++) {
		if (i+j < ans.size()) {
			ans[i+j] = (ans[i+j] + sums[i]*res[j]) % MOD;
		}
	} 
	res = ans;
}

void matrixPow(ll pow) {
	while (pow > 0) {
		if (pow & 1) matrixMult();
		matrixSquare();
		pow >>= 1;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	sums.resize(M+1);
	res.resize(M+1);
	for (int i = 0,x; i < K; i++) {
		cin >> x;
		sums[x]++;
	}
	res[0] = 1;
	ll tot = 0;
	matrixPow(N);
	for (int i = 0; i <= M; i++) tot = (tot + res[i]) % MOD;
	cout << tot;
}
