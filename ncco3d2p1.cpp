#include <bits/stdc++.h>
using namespace std;


const int MAXN = 50005;
int arr[MAXN];
struct Node {
	int L,R;
	int mx,mn;
} seg[4*MAXN];

void build_tree(int v, int L, int R) {
	seg[v].L = L;
	seg[v].R = R;
	if (L == R) {
		seg[v].mx = arr[L];
		seg[v].mn = arr[L];
		return;
	}
	int mid = L+R>>1;
	build_tree(v<<1,L,mid);
	build_tree(v<<1|1,mid+1,R);
	seg[v].mx = max(seg[v<<1].mx,seg[v<<1|1].mx);
	seg[v].mn = min(seg[v<<1].mn,seg[v<<1|1].mn);
}

int qMin(int v, int QL, int QR) {
	int L = seg[v].L, R = seg[v].R;
	if (QR < L || R < QL) {
		return INT_MAX;
	}
	if (QL <= L && R <= QR) {
		return seg[v].mn;
	}
	return min(qMin(v<<1,QL,QR),qMin(v<<1|1,QL,QR));
}

int qMax(int v, int QL, int QR) {
	int L = seg[v].L, R = seg[v].R;
	if (QR < L || R < QL) {
		return INT_MIN;
	}
	if (QL <= L && R <= QR) {
		return seg[v].mx;
	}
	return max(qMax(v<<1,QL,QR),qMax(v<<1|1,QL,QR));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build_tree(1, 1, n);
	int a,b;
	while (q--) {
		cin >> a >> b;
		cout << qMax(1,a,b) - qMin(1,a,b) << "\n";
	}
}