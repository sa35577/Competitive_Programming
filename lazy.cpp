#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 100005;

struct Node {
	int L,R;
	ll minVal;
	ll lazyInc = 0;
	ll lazyAssign = 0;
} seg[MAXN<<2];
ll arr[MAXN];

void build_tree(int v, int L, int R) {
	seg[v].L = L;
	seg[v].R = R;
	if (L == R) {
		seg[v].minVal = arr[L];
		return;
	}
	int mid = (L+R)>>1;
	build_tree(v<<1, L, mid);
	build_tree(v<<1|1, mid+1, R);
	seg[v].minVal = min(seg[v<<1].minVal,seg[v<<1|1].minVal);
}

void push_lazy(int v) {
	int L = seg[v].L, R = seg[v].R;
	if (seg[v].lazyAssign > 0) {
		seg[v].minVal = seg[v].lazyAssign;
		if (L != R) {
			seg[v<<1].lazyAssign = seg[v].lazyAssign;
			seg[v<<1].lazyInc = 0;
			seg[v<<1|1].lazyAssign = seg[v].lazyAssign;
			seg[v<<1|1].lazyInc = 0;
		}
		seg[v].lazyAssign = 0;
	}
	if (seg[v].lazyInc > 0) {
		seg[v].minVal += seg[v].lazyInc;
		if (L != R) {
			seg[v<<1].lazyInc += seg[v].lazyInc;
			seg[v<<1|1].lazyInc += seg[v].lazyInc;
		}
		seg[v].lazyInc = 0;
	}
}

void incRange(int v, int QL, int QR, int val) {
	int L = seg[v].L, R = seg[v].R;
	push_lazy(v);
	if (R < QL || QR < L) return;
	if (QL <= L && R <= QR) {
		seg[v].lazyInc += val;
		push_lazy(v);
		return;
	}
	incRange(v<<1,QL,QR,val); incRange(v<<1|1,QL,QR,val);
	seg[v].minVal = min(seg[v<<1].minVal,seg[v<<1|1].minVal);
}

void setRange(int v, int QL, int QR, int val) {
	int L = seg[v].L, R = seg[v].R;
	push_lazy(v);
	if (R < QL || QR < L) return;
	if (QL <= L && R <= QR) {
		seg[v].lazyAssign = val;
		push_lazy(v);
		return;
	}
	setRange(v<<1,QL,QR,val); setRange(v<<1|1,QL,QR,val);
	seg[v].minVal = min(seg[v<<1].minVal,seg[v<<1|1].minVal);
}

ll minQuery(int v, int QL, int QR) {
	int L = seg[v].L, R = seg[v].R;
	push_lazy(v);
	if (R < QL || QR < L) return LLONG_MAX;
	if (QL <= L && R <= QR) {
		return seg[v].minVal;
	}
	return min(minQuery(v<<1,QL,QR),minQuery(v<<1|1,QL,QR));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build_tree(1, 1, n);
	int qType,L,R,v;
	while (q--) {
		cin >> qType >> L >> R;
		if (qType == 1) {
			cin >> v;
			incRange(1,L,R,v);
		}
		else if (qType == 2) {
			cin >> v;
			setRange(1,L,R,v);
		}
		else {
			cout << minQuery(1,L,R) << "\n";
		}
		/*for (int i = 1; i <= n; i++) {
			cout << minQuery(1,i,i) << " ";
		}
		cout << "\n";*/
	}
}
