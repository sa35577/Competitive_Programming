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

int N,Q;
const int MAXN = 100005;
ll arr[MAXN];
int loc[MAXN];
ll negInf = -1000000000000LL;

struct Node {
    int L,R;
    ll sum,mxP,mxS,mxC; //total, prefix, suffix, contiguous
    
} seg[4*MAXN];

void build_tree(int v, int L, int R) {
    seg[v].L = L; seg[v].R = R;
    if (L == R) {
        loc[L] = v;
        seg[v].sum = seg[v].mxP = seg[v].mxS = seg[v].mxC = arr[L];
        return;
    }
    int mid = (L+R)>>1;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
    seg[v].sum = seg[v<<1].sum + seg[v<<1|1].sum; //update total
    seg[v].mxP = max(seg[v<<1].mxP,seg[v<<1].sum + seg[v<<1|1].mxP); //update prefix
    seg[v].mxS = max(seg[v<<1|1].mxS,seg[v<<1].mxS + seg[v<<1|1].sum); //update suffix
    //update contiguous sum
    seg[v].mxC = max(seg[v<<1].mxC,seg[v<<1|1].mxC); //contiguous sums of children
    seg[v].mxC = max(seg[v].mxC,seg[v<<1].mxS + seg[v<<1|1].mxP); //contiguous of both children
    seg[v].mxC = max(seg[v].mxC,max(seg[v].mxP,seg[v].mxS)); //prefix and suffix sums of current
    seg[v].mxC = max(seg[v].mxC,seg[v].sum); //total sum of node

}

Node query(int v, int QL, int QR) {
    int L = seg[v].L, R = seg[v].R;
    Node res;
    if (R < QL || QR < L) {
        res.L = res.R = 0;
        res.sum = res.mxC = res.mxP = res.mxS = negInf;
        return res;
    }
    if (QL <= L && R <= QR) return seg[v];
    Node UL = query(v<<1,QL,QR), UR = query(v<<1|1,QL,QR);

    seg[v].sum = seg[v<<1].sum + seg[v<<1|1].sum; //update total
    seg[v].mxP = max(seg[v<<1].mxP,seg[v<<1].sum + seg[v<<1|1].mxP); //update prefix
    seg[v].mxS = max(seg[v<<1|1].mxS,seg[v<<1].mxS + seg[v<<1|1].sum); //update suffix
    //update contiguous sum
    seg[v].mxC = max(seg[v<<1].mxC,seg[v<<1|1].mxC); //contiguous sums of children
    seg[v].mxC = max(seg[v].mxC,seg[v<<1].mxS + seg[v<<1|1].mxP); //contiguous of both children
    seg[v].mxC = max(seg[v].mxC,max(seg[v].mxP,seg[v].mxS)); //prefix and suffix sums of current
    seg[v].mxC = max(seg[v].mxC,seg[v].sum); //total sum of node

    res = {L,R,UL.sum + UR.sum,negInf,negInf,negInf};
    res.mxP = max(UL.mxP,UL.sum + UR.mxP);
    res.mxS = max(UR.mxS,UL.mxS + UR.sum);

    res.mxC = max(UL.mxC,UR.mxC);
    res.mxC = max(res.mxC,UL.mxS + UR.mxP);
    res.mxC = max(res.mxC,max(res.mxP,res.mxS));
    res.mxC = max(res.mxC,res.sum);
    return res;
}

void update(int v, int ind, int val) {
    int L = seg[v].L, R = seg[v].R;
    if (L == R) {
        arr[L] = val;
        seg[v].sum = seg[v].mxP = seg[v].mxS = seg[v].mxC = arr[L];

    }
    else {
        int mid = (L+R)>>1;
        if (ind <= mid) {
            update(v<<1,ind,val);
        }
        else {
            update(v<<1|1,ind,val);
        }
        seg[v].sum = seg[v<<1].sum + seg[v<<1|1].sum; //update total
        seg[v].mxP = max(seg[v<<1].mxP,seg[v<<1].sum + seg[v<<1|1].mxP); //update prefix
        seg[v].mxS = max(seg[v<<1|1].mxS,seg[v<<1].mxS + seg[v<<1|1].sum); //update suffix
        //update contiguous sum
        seg[v].mxC = max(seg[v<<1].mxC,seg[v<<1|1].mxC); //contiguous sums of children
        seg[v].mxC = max(seg[v].mxC,seg[v<<1].mxS + seg[v<<1|1].mxP); //contiguous of both children
        seg[v].mxC = max(seg[v].mxC,max(seg[v].mxP,seg[v].mxS)); //prefix and suffix sums of current
        seg[v].mxC = max(seg[v].mxC,seg[v].sum); //total sum of node
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N >> Q;
    rep(i,0,N,1) {
        cin >> arr[i];
    }
    build_tree(1,0,N-1);
    char op;
    int v1,v2;
    rep(i,0,Q,1) {
        cin >> op >> v1 >> v2;
        if (op == 'S') {
            --v1;
            update(1,v1,v2);
        }
        else if (op == 'Q') {
            --v1;
            --v2;
            printf("%lld\n",query(1,v1,v2).mxC);
        }
    }
    
}