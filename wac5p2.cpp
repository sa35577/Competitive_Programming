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
int n,q;
int A[200005];

struct Node {
    int L,R;
    int mn,mx;
} seg[4*200005];

void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        seg[v].mn = A[L]; 
        seg[v].mx = A[L];
        return;
    }
    int mid = (L+R)>>1;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
    seg[v].mn = min(seg[v<<1].mn,seg[v<<1|1].mn);
    seg[v].mx = max(seg[v<<1].mx,seg[v<<1|1].mx);      
}

int mnQuery(int v, int lo) {
    int L = seg[v].L, R = seg[v].R;
    if (seg[v].mn >= lo) {
        return seg[v].R-seg[v].L+1;
    }
    if (L == R) return INT_MIN;
    if (seg[v<<1].mn >= lo) {
        return seg[v<<1].R-seg[v<<1].L+1+max(0,mnQuery(v<<1|1,lo));
    }
    else {
        return mnQuery(v<<1,lo);
    }
}

int mxQuery(int v, int hi) {
    int L = seg[v].L, R = seg[v].R;
    if (seg[v].mx <= hi) {
        return seg[v].R-seg[v].L+1;
    }
    if (L == R) return INT_MIN;
    if (seg[v<<1].mx <= hi) {
        return seg[v<<1].R-seg[v<<1].L+1+max(0,mxQuery(v<<1|1,hi));
    }
    else {
        return mxQuery(v<<1,hi);
    }
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n,q;
    cin >> n >> q;
    repr(i,n-1,-1,1) {
        cin >> A[i];
    }
    build_tree(1,0,n-1);
    int L,eps;
    rep(query,0,q,1) {
        cin >> L >> eps;
        printf("%d\n",max(0,min(mnQuery(1,L-eps),mxQuery(1,L+eps))));
    }
}