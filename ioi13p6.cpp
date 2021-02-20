#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MXSIZE = 1000000000;


struct n1 {
	int l = 0,r = MXSIZE;
	ll val = 0;
	n1 *child[2] = {NULL,NULL};
	n1(int L, int R) {
		l = L; r = R;
	}
};


struct n2 {
	
	n2() : dimNode(0,MXSIZE) {};
	n2 *child[2] = {NULL,NULL};
	n1 dimNode;
};



ll q2(n1 *cur, int QL, int QR) {
	if (cur == NULL || QR < cur->l || cur->r < QL) {
		return 0LL;
	}
	if (QL <= cur->l && cur->r <= QR) return cur->val;
	return __gcd(q2(cur->child[0],QL,QR),q2(cur->child[1],QL,QR));
}

ll q1(n2 *cur, int L, int R, int x1, int x2, int y1, int y2) {
	if (cur == NULL || x2 < L || R < x1) return 0LL;
	if (x1 <= L && R <= x2) return q2(&cur->dimNode,y1,y2);
	int mid = (L+R)>>1;
	return __gcd(q1(cur->child[0],L,mid,x1,x2,y1,y2),
	q1(cur->child[1],mid+1,R,x1,x2,y1,y2));
}

inline void upd2(n1 *cur, int idx, ll val) {
	int L = cur->l, R = cur->r, mid = (L+R)>>1;
	if (L == R) {
		cur->val = val;
		return;
	}
	n1 *&nxt = cur->child[idx>mid];
	if (nxt == NULL) {
		nxt = new n1(idx,idx);
		nxt->val = val;
	}
	else if (nxt->l <= idx && idx <= nxt->r) 		upd2(nxt,idx,val);
	else {
		do {
			if (idx <= mid) R = mid;
			else L = mid+1;
			mid = (L+R)>>1;
		} while( ((idx <= mid) && (nxt->l <= mid)) || ((idx > mid) && (nxt->l > mid)));
		n1 *nxt2 = new n1(L,R);
		if (nxt->l > mid) {
			nxt2->child[1] = nxt;
		}
		else {
			nxt2->child[0] = nxt;
		}
		nxt = nxt2;
		upd2(nxt2,idx,val);

	}
	cur->val = __gcd(cur->child[0] != NULL ? cur->child[0]->val : 0, cur->child[1] != NULL ? cur->child[1]->val : 0);
}

inline void upd1(n2 *cur, int L, int R, int x, int y, ll val) {
	if (L == R) {
		 upd2(&cur->dimNode,y,val);
		 return;
	}
	int mid = (L+R)>>1;
	if (x <= mid) R = mid;
	else L = mid + 1;
	if (cur->child[x>mid] == NULL) cur->child[x>mid] = new n2();
	upd1(cur->child[x>mid],L,R,x,y,val);
	upd2(&cur->dimNode,y,__gcd(cur->child[0] != NULL ? q2(&cur->child[0]->dimNode,y,y) : 0,cur->child[1] != NULL ? q2(&cur->child[1]->dimNode,y,y) : 0));

}

n2 *root;
void init(int R, int C) {
	root = new n2();
}
void update(int P, int Q, ll K) {
	upd1(root,0,MXSIZE,P,Q,K);
}
ll calculate(int P, int Q, int U, int V) {
	return q1(root,0,MXSIZE,P,U,Q,V);
}

/*int main() {
	cin.sync_with_stdio((0));
	cin.tie(0); cout.tie(0);
	int r,c,n;
	int tc;
	int p,q,u,v;
	ll k;
	cin >> r >> c >> n;
	init(r,c);
	for (int cnt = 0; cnt < n; cnt++) {
		cin >> tc;
		if (tc == 1) {
			cin >> p >> q >> k;
			update(p,q,k);
		}
		else if (tc == 2) {
			cin >> p >> q >> u >> v;
			cout << calculate(p, q, u, v) << "\n";
		}
	}
	return 0;

}*/