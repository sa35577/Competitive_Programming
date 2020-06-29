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


/*---END OF TEMPLATE---*/
const int MAXN = 100005;
int N,Q;
vi trees;


struct query {
    int L,R,threshold;
};
struct Node {
    int L,R,minValue,sum;
    bool nothing;
} seg[4*MAXN];

void build_tree(int L, int R, int v) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        if (trees[L] == 0) {
            seg[v].minValue = INT_MAX;
            seg[v].sum = 0;
            seg[v].nothing = true;
        }
        else {
            seg[v].minValue = trees[L];
            seg[v].sum = trees[L];
            seg[v].nothing = false;
        }
        return;
    }
    int mid = (L+R)/2;
    build_tree(L,mid,v*2);
    build_tree(mid+1,R,v*2+1);
    seg[v].minValue = min(seg[v*2].minValue,seg[v*2+1].minValue);
    seg[v].sum = seg[v*2].sum + seg[v*2+1].sum;
    seg[v].nothing = (seg[v].sum == 0);
    if (seg[v].sum == 0) seg[v].nothing = true;
    else seg[v].nothing = false;

}


int Query(int v, int QL, int QR, int mn) {
    int L = seg[v].L, R = seg[v].R;
    if (R < QL || QR < L) return 0;
    if (QL <= L && R <= QR) {
        if (seg[v].nothing) return 0;
        if (seg[v].minValue >= mn) return seg[v].sum;
        if (L == R) return 0;
    }
    return Query(v*2,QL,QR,mn) + Query(v*2+1,QL,QR,mn);
}








int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N);
    int val;
    rep(i,0,N,1) {
        scan(val);
        trees.push_back(val);
    }
    scan(Q);
    query queries[100000];
    int minQuery = INT_MAX;
    rep(i,0,Q,1) {
        scan(queries[i].L);
        scan(queries[i].R);
        scan(queries[i].threshold);
        minQuery = min(minQuery,queries[i].threshold);
    }
    rep(i,0,N,1) {
        if (trees[i] < minQuery) trees[i] = 0;
    }
    build_tree(0,N-1,1);
    rep(i,0,Q,1) {
        cout << Query(1,queries[i].L,queries[i].R,queries[i].threshold) << endl;
    }




}