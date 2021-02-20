#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> diff;
int N,Q;

int v[200005], n[200005];

int main() {
	fill(v,v+200005,INT_MAX);
	fill(n,n+200005,INT_MAX);
	diff.push_back({-2000000001, 0});
	diff.push_back({2000000001, 0});
	//ifstream file("Interdiff.txt");
	cin >> N >> Q;
	for (int i = 0,a,b; i < N; i++) {
		cin >> a >> b;
		diff.push_back({a,1});
		diff.push_back({b+1,-1});
	}
	sort(diff.begin(), diff.end());
	for (int i = 1; i < diff.size(); i++) diff[i].second += diff[i - 1].second;
	for (int i = 0; i < diff.size(); i++) {
		n[i] = diff[i].first;
		v[i] = diff[i].second;
	}
	for (int i = 0,q; i < Q; i++) {
		cin >> q;
		cout << v[upper_bound(n,n+200004,q)-n-1] << "\n";
	}
}