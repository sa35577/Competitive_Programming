#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1e5+5;
int bit[MAXT<<1];
int T;
int arr[MAXT];
set<int> s;
map<int,int> keys;
double avgRank = 0;


int query(int v) {
	int sum = 0;
	for (; v > 0; v-= v&(-v)) {
		sum += bit[v];
	}
	return sum;
}

void update(int v) {
	for (; v < MAXT<<1; v += v&(-v)) bit[v]++;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	int inc = 1;
	for (auto &val : s) {
		keys[val] = inc++;
	}
	for (int i = 0; i < T; i++) {
		avgRank += i - query(keys[arr[i]]) + 1;
		update(keys[arr[i]]);
	}
	printf("%.2f",(avgRank/T));
}