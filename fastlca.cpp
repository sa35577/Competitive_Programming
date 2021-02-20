#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MAXN = 6000005;
bitset<MAXN> vis;
int arr[MAXN];

int main() {
	cin.sync_with_stdio(0); 
	cin.tie(0);
	
	
	int n,q;
	cin >> n;
	cin >> q;
	arr[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		cin >> arr[i];
	}
	int a,b,res;
	
	for (int qq = 0; qq < q; qq++) {
		cin >> a >> b;
		res = b;
		while (b) {
			vis[b] = 1;
			b = arr[b];
		}
		while (a) {
			if (vis[a]) {
				cout << a << endl;
				break;
			}
			a = arr[a];
		}
		while (res) {
			vis[res] = 0;
			res = arr[res];
		}

	}
	return 0;
}