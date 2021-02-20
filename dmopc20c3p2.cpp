#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

const int MAXM = 200005, MAXN = 25;
const ll MULT = 1000000005LL;
int N,M;
ll K,x;
vector<vector<ll>> v;

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	cin >> M >> N >> K;
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	v.resize(N-1);
	for (int i = 0; i < N-1; i++) v[i].resize(M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			
			if (j < N-1) {
				v[j][i] += x*MULT;
			} 
			if (j > 0) {
				v[j-1][i] += x;
			}
		}
		
	}
	for (int i = 0; i < N-1; i++) sort(v[i].begin(),v[i].end());
	ll tot = 0;
	int cntCur;
	int lowNxt,highNxt;
	
	vector<ll>::iterator hi,low,hiCur;
	for (int k = 0; k < v.size(); k++) {

		vector<ll> arr = v[k];
		int i;
		for (i = 0; i < M; i++) {
			ll cur = arr[i];
			hiCur = upper_bound(arr.begin(),arr.end(),cur);
			if (hiCur == arr.end()) break;
			else cntCur = (hiCur-arr.begin());
			cntCur = cntCur-i; //dont include last
			low = lower_bound(arr.begin(),arr.end(),cur+K*MULT+K);
			hi = upper_bound(arr.begin(),arr.end(),cur+K*MULT+K);
			if (low != arr.end()) {
				lowNxt = low-arr.begin();
				highNxt = hi-arr.begin()-1;
				if (arr[lowNxt] == cur+K*MULT+K) {
					tot += (highNxt-lowNxt+1)*cntCur;
				}
				i = hiCur-arr.begin()-1;
			}
			else i = M;
		}
	}
	cout << tot << "\n";

	


}