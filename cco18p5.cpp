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
#define ld long double
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

const int MAXN = 2000010;
int n,k,q;
struct Node {
    int L,R,val;
} seg[4*MAXN];
int arr[MAXN],loc[MAXN];

void build_tree(int v, int L, int R) {
    seg[v].L = L; 
    seg[v].R = R;
    if (L == R) {
        seg[v].val = arr[L];
        loc[L] = v;
        return;
    }
    int mid = (L+R)>>1;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
    seg[v].val = max(seg[v<<1].val,seg[v<<1|1].val);
}

void update(int idx, int val) {
    idx = loc[idx];
    seg[idx].val = val;
    idx >>= 1;
    while (idx > 0) {
        seg[idx].val = max(seg[idx<<1].val,seg[idx<<1|1].val);
        idx >>= 1;
    }
}






int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> n >> k >> q;
    rep(i,1,n+1,1) {
        cin >> a[i];
    }
    build_tree(1,1,N);

    cout << seg[1].val << endl;

    
}

