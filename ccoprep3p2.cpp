#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int MAXN = 2000005;
ll pref[MAXN],arr[MAXN],dp[MAXN];
deque<int> stck;
int n,l;

ld calculate(int n1, int n2) {
	ll x1 = pref[n1] + n1, x2 = pref[n2] + n2;
	return (ld)(dp[n2]-dp[n1] + x2*x2-x1*x1)/((ld)2*(x2-x1));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);	
	cin >> n >> l;
	l++;
	dp[0] = 0;
	stck.push_back(0);
	for (int i = 1; i < n+1; i++) {
		cin >> arr[i];
		pref[i] = arr[i] + pref[i-1];
		dp[i] = LONG_MAX;
		while (stck.size() > 1 && calculate(stck.front(),stck[1]) <= pref[i]+i-l) stck.pop_front();	
		ll val = pref[i]+i-pref[stck.front()]-stck.front()-l;
		dp[i] = dp[stck.front()] + val*val;
		while (stck.size() > 1 && calculate(stck[stck.size()-2],stck.back()) >= calculate(stck.back(),i)) stck.pop_back();
		stck.push_back(i);
	}
	cout << dp[n] << "\n";
	

}