#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100005;

struct Node {
	int L,R;
	bitset<1001> b;
} seg[4*MAXN];
int arr[MAXN];

int freq[1001];
unordered_map<int, int> keytoVal,valtoKey;
deque<int> ava;

int n,q;

void build_tree(int v, int L, int R) {
	seg[v].L = L, seg[v].R = R;
	if (L == R) {
		seg[v].b[valtoKey[arr[L]]] = 1;
		return;
	}
	int mid = L+R>>1;
	build_tree(v<<1, L, mid);
	build_tree(v<<1|1, mid+1, R);
	seg[v].b = seg[v<<1].b|seg[v<<1|1].b;
}

bitset<1001> query(int v, int QL, int QR) {
	int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return seg[0].b;
    if (QL <= L && R <= QR) return seg[v].b;
    return query(v<<1,QL,QR)|query(v<<1|1,QL,QR);
}

void fnd(int v, int idx, int newVal) {
	int L = seg[v].L, R = seg[v].R;
	if (R < idx || idx < L) return;
	if (L == idx && idx == R) {
		seg[v].b.reset();
		--freq[valtoKey[arr[L]]];
		if (!freq[valtoKey[arr[L]]]) {
			ava.push_back(valtoKey[arr[L]]);
			keytoVal.erase(valtoKey[arr[L]]);
			valtoKey.erase(arr[L]);
		}
		arr[L] = newVal;
		if (valtoKey.find(arr[L]) == valtoKey.end()) {
			keytoVal[ava.front()] = arr[L];
			valtoKey[arr[L]] = ava.front();
			ava.pop_front();
		}
		++freq[valtoKey[arr[L]]];
		seg[v].b[valtoKey[arr[L]]] = 1;
		return;

	}
	fnd(v<<1,idx,newVal);fnd(v<<1|1,idx,newVal); 
	seg[v].b = seg[v<<1].b|seg[v<<1|1].b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= 1000; i++) ava.push_back(i);
	memset(freq,0,sizeof(freq));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (valtoKey.find(arr[i]) == valtoKey.end()) {
			keytoVal[ava.front()] = arr[i];
			valtoKey[arr[i]] = ava.front();
			ava.pop_front();
		}
		++freq[valtoKey[arr[i]]];
	}
	build_tree(1,1,n);

	int qType,v1,v2;
	while (q--) {
		cin >> qType >> v1 >> v2;
		if (qType & 1) {
			fnd(1,v1,v2);

		}
		else {
			cout << query(1,v1,v2).count() << endl;
		}
	}


}