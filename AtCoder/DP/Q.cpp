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

int N;
const int MAXN = 200005;
unordered_map<int,int> mp;



struct Entry {
    int h;
    ll val;
} arr[MAXN];

struct Node {
    int L,R;
    ll mx;
}seg[4*MAXN];


void buildTree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        seg[v].mx = 0;
        mp[L] = v;
        return;
    }
    int mid = (L+R)/2;
    buildTree(v*2,L,mid);
    buildTree(v*2+1, mid+1,R);
    seg[v].mx = max(seg[v*2].mx,seg[v*2+1].mx);
}

void update(ll val, int U) {
    int v = mp[U];
    while (v > 0) {
        if (val > seg[v].mx) {
            seg[v].mx = val;
            v = v/2;
        }
        else break;
    }
}

ll query(int v, int QL, int QR) {
    int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return 0;
    if (QL <= L && R <= QR) {
        return seg[v].mx;
    }
    return max(query(v*2,QL,QR),query(v*2+1,QL,QR));
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N;
    rep(i,0,N,1) {
        cin >> arr[i].h;
        arr[i].h--;
    }
    rep(i,0,N,1) {
        cin >> arr[i].val;
    }
    buildTree(1,0,N-1);
    rep(i,0,N,1) {
        ll nxtVal = query(1,0,arr[i].h)+arr[i].val;
        update(nxtVal,arr[i].h);
    }
    cout << query(1,0,N-1);

}