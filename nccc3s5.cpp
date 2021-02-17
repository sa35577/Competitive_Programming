#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXP = 2000005;
struct Node {
	int L,R;
	ll sumCones=0;
	ll numCones=0;
	ll lazyInc=0;
	bool lazyReset=0;
	void clear() {
		sumCones = 0;
		numCones = 0;
		lazyInc = 0;
		lazyReset = 1;
	}
	int size() {
		return R-L+1;
	}
	 
} seg[MAXP<<2];

ll sumTo(ll n) {
	return (n*(n+1))>>1;
}

void build_tree(int v, int L, int R) {
	seg[v].L = L;
	seg[v].R = R;
	if (L == R) return;
	int mid = (L+R)>>1;
	build_tree(v<<1,L,mid); build_tree(v<<1|1,mid+1,R);
}

void push_lazy(int v) {
	int L = seg[v].L, R = seg[v].R, mid = (L+R)>>1;
    if (seg[v].size() > 1) {
		if (seg[v].lazyReset) {
			seg[v<<1].clear();
			seg[v<<1|1].clear();
		}
		
		ll sumL = sumTo(mid)-sumTo(L-1), sumR = sumTo(R)-sumTo(mid);
		seg[v<<1].sumCones += seg[v].lazyInc*sumL;
		seg[v<<1].numCones += seg[v].lazyInc * seg[v<<1].size();
		seg[v<<1].lazyInc += seg[v].lazyInc;
		seg[v<<1|1].sumCones += seg[v].lazyInc*sumR;
		seg[v<<1|1].numCones += seg[v].lazyInc*seg[v<<1|1].size();
		seg[v<<1|1].lazyInc += seg[v].lazyInc;
		
    }
    seg[v].lazyReset = 0;
	seg[v].lazyInc = 0;
    
    
}

void add(int v, int QL, int QR, ll cnt) {
	int L = seg[v].L, R = seg[v].R;
	push_lazy(v);
	if (seg[v].L == QL && seg[v].R == QR) {
		ll sum = sumTo(R)-sumTo(L-1);
		seg[v].sumCones += cnt*sum;
		seg[v].numCones += seg[v].size()*cnt;
		seg[v].lazyInc += cnt;
		seg[v].lazyReset = 0;//
		return;
	}
	int mid = (L+R)>>1;
	if (QR <= mid) add(v<<1,QL,QR,cnt);
	else if (QL > mid) add(v<<1|1,QL,QR,cnt);
	else {
		add(v<<1,QL,mid,cnt);
		add(v<<1|1,mid+1,QR,cnt);
	}
	seg[v].sumCones = seg[v<<1].sumCones + seg[v<<1|1].sumCones;
	seg[v].numCones = seg[v<<1].numCones + seg[v<<1|1].numCones;

}

ll buyAmt(int v, ll Q) {
	int L = seg[v].L, R = seg[v].R;
    push_lazy(v);

    ll ans;
	if (seg[v].sumCones <= Q) {
		ans = seg[v].numCones;
		seg[v].clear();
		return ans;
	}
    if (L == R) {
        ans = Q/L;
        seg[v].numCones -= ans;
        seg[v].sumCones -= ans*L;
		seg[v].lazyInc -= ans;
		seg[v].lazyReset = 0;//
        return ans;
    }
    if (seg[v<<1].sumCones >= Q) ans = buyAmt(v<<1,Q);
    else {
		ll sto = seg[v<<1].sumCones;
        ans = buyAmt(v<<1,Q) + buyAmt(v<<1|1,Q-sto);
    }
    seg[v].sumCones = seg[v<<1].sumCones + seg[v<<1|1].sumCones;
	seg[v].numCones = seg[v<<1].numCones + seg[v<<1|1].numCones;
    return ans;
}



ll buyLow(int v, ll Q) {
	int L = seg[v].L, R = seg[v].R;
    push_lazy(v);
    ll ans;
	if (seg[v].numCones <= Q) {
		ans = seg[v].sumCones;
		seg[v].clear();
		return ans;
	}
    if (L == R) {
        ans = L * Q;
		seg[v].numCones -= Q;
		seg[v].sumCones -= ans;
		seg[v].lazyInc -= Q;
		seg[v].lazyReset = 0;//
        return ans;
    }

	if (seg[v<<1].numCones >= Q) {
		ans = buyLow(v<<1,Q);
	}
	else {
		ll sto = seg[v<<1].numCones;
		ans = buyLow(v<<1,Q) + buyLow(v<<1|1,Q-sto);
	}
    
    
    seg[v].sumCones = seg[v<<1].sumCones + seg[v<<1|1].sumCones;
	seg[v].numCones = seg[v<<1].numCones + seg[v<<1|1].numCones;
    return ans;
}

ll buyHigh(int v, ll Q) {
	int L = seg[v].L, R = seg[v].R;
    push_lazy(v);
    ll ans;
	if (seg[v].numCones <= Q) {
		ans = seg[v].sumCones;
		seg[v].clear();
		return ans;
	}
    if (L == R) {
        ans = L * Q;
		seg[v].numCones -= Q;
		seg[v].sumCones -= ans;
		seg[v].lazyInc -= Q;
		seg[v].lazyReset = 0;//
        return ans;
    }
    
    
	if (seg[v<<1|1].numCones >= Q) {
		ans = buyHigh(v<<1|1,Q);
	}
	else {
		ll sto = seg[v<<1|1].numCones;
		ans = buyHigh(v<<1|1,Q) + buyHigh(v<<1,Q-sto);
	}
    
    seg[v].sumCones = seg[v<<1].sumCones + seg[v<<1|1].sumCones;
	seg[v].numCones = seg[v<<1].numCones + seg[v<<1|1].numCones;
    return ans;
}

ll cost(int v, ll Q) {
    int L = seg[v].L, R = seg[v].R;
	push_lazy(v);
	ll ans;
	if (Q > seg[v].numCones) return -1;
    if (L == R) return L;
    if (seg[v<<1].numCones >= Q) {
        ans = cost(v<<1,Q);
    }
    else ans = cost(v<<1|1,Q-seg[v<<1].numCones);
	seg[v].sumCones = seg[v<<1].sumCones + seg[v<<1|1].sumCones;
	seg[v].numCones = seg[v<<1].numCones + seg[v<<1|1].numCones;
	return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll N,K,P,A,B;
    ll Q,L;
    string qType;
    cin >> N;
    build_tree(1,1,MAXP);
    while (N--) {
        cin >> qType;
        if (qType == "ADD") {
            cin >> K >> P;
            add(1,P,P,K);
        }
        else if (qType == "ADDRANGE") {
            cin >> A >> B;
            add(1,A,B,1);
        }
        else if (qType == "BUYAMT") {
            cin >> Q;
            cout << buyAmt(1,Q) << "\n";
			
        }
        else if (qType == "BUYLOW") {
            cin >> L;
            cout << buyLow(1,L) << "\n";

        }
        else if (qType == "BUYHIGH") {
            cin >> L;
            cout << buyHigh(1,L) << "\n";
        }
        else if (qType == "COST") {
            cin >> L;
			cout << cost(1,L) << "\n";
        }
        else if (qType == "NUMCONES") {
            cout << seg[1].numCones << "\n";
        }
        else if (qType == "TOTALCOST") {
            cout << seg[1].sumCones << "\n";
        }        
    }
}