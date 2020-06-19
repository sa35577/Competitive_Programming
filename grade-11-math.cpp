#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 500000;
const long long MOD = 1000000007;
string arr;
long long magS,M;
long long fastPow(long long base, long long power) {
    long long res = 1;
    while (power > 0) {
        if (power % 2 == 1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        power /= 2;
    }
    return res;
}
struct Node {
    long long L,R;
    long long val;
    bool fullInRange;
} seg[4*MAXN];

void build_tree(long long v, long long L, long long R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        if (arr[L] == '1') {
            seg[v].val = fastPow(2,magS-L-1);
            seg[v].fullInRange = 1;
        }
        else {
            seg[v].val = 0;
            seg[v].fullInRange = 0;
        }
        return; 
    }
    build_tree(v*2,L,(L+R)/2);
    build_tree(v*2+1,(L+R)/2 + 1, R);
    seg[v].val = (seg[v*2].val + seg[v*2+1].val) % MOD;
    seg[v].fullInRange = seg[v*2].fullInRange && seg[v*2+1].fullInRange;
}
long long setFu(long long v) {
    long long L = seg[v].L, R = seg[v].R;
    if (seg[v].fullInRange == 1) {
        return seg[v].val;
    }
    if (L == R) {
        seg[v].val = fastPow(2,magS-L-1);
        seg[v].fullInRange = 1;
        return seg[v].val;
    }
    setFu(v*2);
    setFu(v*2+1);
    seg[v].val = (seg[v*2].val + seg[v*2+1].val)%MOD;
    seg[v].fullInRange = 1;
    return seg[v].val;
}

void update(long long v, long long UL, long long UR) {
    long long L = seg[v].L, R = seg[v].R;
    if (R < UL || UR < L) {
        return;
    }
    if (UL <= L && R <= UR) {
        if (seg[v].fullInRange == 1) return;
        long long dummy = setFu(v);
        return;
    }
    update(v*2,UL,UR);
    update(v*2+1,UL,UR);
    seg[v].val = (seg[v*2].val + seg[v*2+1].val)%MOD;
    seg[v].fullInRange = seg[v*2].fullInRange && seg[v*2+1].fullInRange;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> magS >> M;
    cin >> arr;
    build_tree(1,0,magS-1);
    for (long long i = 0; i < M; i++) {
        long long l,r;
        cin >> l >> r;
        l--; r--;
        update(1,l,r);
        cout << seg[1].val << endl;

    }
}