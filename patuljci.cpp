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

int N,C,Q;
const int MAXN = 300005, MAXC = 10005;
int arr[MAXN];
vector<int> colPos[MAXC];
struct Node {
    int L,R,val;
} seg[4*MAXN];

int cnt(int color, int QL, int QR) {
    return upper_bound(colPos[color].begin(),colPos[color].end(),QR) - lower_bound(colPos[color].begin(),colPos[color].end(),QL);
}

void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        seg[v].val = arr[L];
        return;
    }
    int mid = (L+R)/2;
    build_tree(v*2,L,mid);
    build_tree(v*2+1,mid+1,R);
    if (cnt(seg[v*2].val,L,R) > cnt(seg[v*2+1].val,L,R)) {
        seg[v].val = seg[v*2].val;
    }
    else seg[v].val = seg[v*2+1].val;
}

int query(int v, int QL, int QR) {
    int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return 0;
    if (QL <= L && R <= QR) return seg[v].val;
    int q1 = query(v*2,QL,QR), q2 = query(v*2+1,QL,QR);
    if (q1 == q2) return q1;
    if (cnt(q1,QL,QR) > cnt(q2,QL,QR)) {
        return q1;
    }
    return q2;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N); scan(C);
    rep(i,0,N,1) {
        scan(arr[i]);
        colPos[arr[i]].push_back(i);
    }
    build_tree(1,0,N-1);
    scan(Q);
    int left,right;
    rep(i,0,Q,1) {
        scan(left);
        scan(right); 
        left--; right--;
        int res = query(1,left,right);
        if (cnt(res,left,right) > (right-left+1)/2) {
            cout << "yes " << res << endl;
        }
        else cout << "no" << endl;
        
    }
}