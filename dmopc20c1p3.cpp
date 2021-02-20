#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int arr[MAXN];
pair<int,long long> inc[MAXN],decr[MAXN];/*
pair<value,trans*/

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	arr[0] = INT_MIN;
	arr[n+1] = INT_MIN;
	inc[0] = {INT_MIN,0};
	decr[n+1] = {INT_MIN,0};
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] >= inc[i-1].first) {
			inc[i] = {arr[i],inc[i-1].second};
		}
		else {
			inc[i] = {inc[i-1].first,inc[i-1].second-arr[i]+inc[i-1].first};
		}
	}
	if (n < 3) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = n; i > 0; i--) {
		if (arr[i] >= decr[i+1].first) {
			decr[i] = {arr[i],decr[i+1].second};
		}
		else {
			decr[i] = {decr[i+1].first,decr[i+1].second-arr[i]+decr[i+1].first};
		}
	}
	long long mn = LLONG_MAX;
	mn = min(decr[1].second,inc[n].second);
	for (int i = 2; i < n; i++) {
		mn = min(mn,inc[i-1].second+decr[i+1].second-min(0,arr[i]-max(inc[i-1].first,decr[i+1].first)));
	}
	cout << mn << "\n";

}