#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100005;
struct Node {
	int L,R,mn;
} seg[4*MAXN];
int n,m;

void build_tree(int v, int L, int R) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	seg[v].L = L;
	seg[v].R = R;
	if (L == R) {
		cin >> seg[v].mn;
		return;
	}
	int mid = (L+R)>>1;
	build_tree(v<<1,L,mid);
	build_tree(v<<1|1,mid+1,R);
	seg[v].mn = min(seg[v<<1].mn,seg[v<<1|1].mn);
}

int findIdx(int v, int idx) {
	int L = seg[v].L, R = seg[v].R;
	if (idx < L || R < idx) {
		return -1;
	}
	if (L == R && L == idx) return v;
	return max(findIdx(v<<1,idx),findIdx(v<<1|1,idx));
}

void update(int v, int val) {
	int L = seg[v].L, R = seg[v].R;
	seg[v].mn = val;
	v >>= 1;
	while (v) {
		seg[v].mn = min(seg[v<<1].mn,seg[v<<1|1].mn);
		v >>= 1;
	}
}

int query(int v, int QL, int QR) {
	int L = seg[v].L, R = seg[v].R;
	if (QR < L || R < QL) {
		return INT_MAX;
	}
	if (QL <= L && R <= QR) {
		return seg[v].mn;
	}
	return min(query(v<<1,QL,QR),query(v<<1|1,QL,QR));
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	build_tree(1,0,n-1);
	int i,x,j;
	char q;
	for (int cnt = 0; cnt < m; cnt++) {
		cin >> q;
		if (q == 'M') {
			cin >> i >> x;
			update(findIdx(1,i),x);
		}
		else if (q == 'Q') {
			cin >> i >> j;
			cout << query(1,i,j) << "\n";
		}
	}
}