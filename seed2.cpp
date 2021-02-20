#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll L, ll R) {
	ll mid = (L+R)/2;
	cout << mid << "\n";
	cout << flush;
	string s;
	cin >> s;
	if (s == "OK") return;
	else if (s == "FLOATS") solve(L,mid-1);
	else if (s == "SINKS") solve(mid+1,R);
}


int main() {
	solve(1LL,2000000000LL);
}