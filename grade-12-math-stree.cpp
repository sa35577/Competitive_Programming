#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/


unordered_map<int,int>::iterator it;
const int MAXN = 500000;

struct Node {
    unordered_map<int,int> mp;
    int L,R,value=-1;
} seg[4*MAXN];

void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        seg[v].mp[0] = 1;
        seg[v].value = 0;
        return;
    }
    build_tree(v*2,L,(L+R)/2);
    build_tree(v*2+1,(L+R)/2 + 1, R);
    seg[v].mp[0] = R-L+1;
}
void unite(int v, int old, int t) {
    if (v == 0) return;
    seg[v].mp[old]--;
    old += t;
    if (seg[v].mp.find(old) != seg[v].mp.end()) seg[v].mp[old]++;
    else seg[v].mp[old] = 1;
    old -= t;
    if (seg[v].mp[old] == 0) seg[v].mp.erase(old);
    unite(v/2,old,t);
}
void crement(int v, int QL, int QR, int t) {
    int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return;
    if (QL <= L && R <= QR) {
        int ind=seg[v].value,val;
        seg[v].mp[ind]--;
        ind += t;
        seg[v].mp[ind] = 1;
        ind -= t;
        if (seg[v].mp[ind] == 0) seg[v].mp.erase(ind);
        unite(v/2,ind,t);
        return;
    }
    crement(v*2,QL,QR,t);
    crement(v*2+1,QL,QR,t);
}

int query(int v, int QL, int QR, int val) {
    int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return 0;
    if (QL <= L && R <= QR) {
        if (seg[v].mp.find(val) != seg[v].mp.end()) { 
            return seg[v].mp[val];
        }
        return 0;
    }
    return query(v*2,QL,QR,val) + query(v*2+1,QL,QR,val);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n,q;
    cin >> n >> q;
    build_tree(1,0,n-1);
    int qt,l,r,c;
    rep(i,0,q,1) {
        cin >> qt >> l;
        --l;
        if (qt == 1) {
            crement(1,l,l,1);
        }
        else if (qt == 2) {
            crement(1,l,l,-1);
        }
        else if (qt == 3) {
            cin >> r; cin >> c;
            --r;
            cout << query(1,l,r,c) << "\n";
        }
    }
}