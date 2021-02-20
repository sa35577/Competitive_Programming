#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MAXN = 200005;
int tol[MAXN],dead[MAXN];
vector<int> addLeech[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> tol[i];
	int Q;
	cin >> Q;
	for (int i = 1,L,R; i <= Q; i++) {
		cin >> L >> R;
		addLeech[L].push_back(i);
		addLeech[R+1].push_back(-i);
	}
	ordered_set os;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		for (int x : addLeech[i]) {
			if (x > 0) os.insert(x),tot++;
			else os.erase(-x),tot--;
		}
		if (tot > tol[i]) {
			dead[*os.find_by_order(tol[i])]++;
		}
	}
	for (int i = 1; i <= Q; i++) cout << dead[i] << "\n";

}