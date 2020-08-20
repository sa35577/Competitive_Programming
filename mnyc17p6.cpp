#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/
unordered_set<int>::iterator it;
unordered_map<int,int> treeSpot;


unordered_set<int> combineSets(unordered_set<int> s1, unordered_set<int> s2) {
    unordered_set<int> res;
    for (it = s1.begin(); it != s1.end(); it++) {
        res.insert(*it);
    }
    for (it = s2.begin(); it != s2.end(); it++) {
        res.insert(*it);
    }
    return res;
} 


const int MAXN = 100000;
int arr[MAXN];
struct Node {
    int L,R;
    unordered_set<int> st;
} seg[4*MAXN];


void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        seg[v].st.insert(arr[L]);
        treeSpot[L] = v;
        return;
    }
    int mid = (L+R)>>1;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
    seg[v].st = combineSets(seg[v<<1].st,seg[v<<1|1].st);
}

void update(int ind, int val) {
    int idx = treeSpot[ind];
    seg[idx].st.clear(); 
    seg[idx].st.insert(val);
    idx >>= 1;
    while (idx != 0) {
        seg[idx].st = combineSets(seg[idx<<1].st,seg[idx<<1|1].st);
        idx >>= 1;
    }
}

unordered_set<int> query(int v, int QL, int QR) {
    int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return (unordered_set<int>());
    if (QL <= L && R <= QR) return seg[v].st;
    return combineSets(query(v<<1,QL,QR),query(v<<1|1,QL,QR));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n,q;
    scan(n); scan(q);
    rep(i,0,n,1) scan(arr[i]);
    build_tree(1,0,n-1);
    int qType,l,r;
    rep(i,0,q,1) {
        scan(qType); scan(l); scan(r);
        if (qType == 1) {
            l--;
            update(l,r);
        }
        else {
            l--; r--;
            printf("%ld\n",query(1,l,r).size());
        }
    }
}