#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int arr[MAXN],freq[MAXN];
deque<int> used;
bitset<MAXN> inUsed;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i],freq[arr[i]]++;
	for (int i = 1; i <= N; i++) {
		freq[arr[i]]--;
		if (inUsed[arr[i]]) continue;
		while (used.size() > 0 && used.back() > arr[i] && freq[used.back()] > 0) {
			inUsed[used.back()] = 0;
			used.pop_back();
		}
		if (!inUsed[arr[i]]) used.push_back(arr[i]),inUsed[arr[i]] = 1;
	}
	while (used.size() > 1) {
		cout << used.front() << " ";
		used.pop_front();
	}
	cout << used.front() << "\n";
}