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

const int MAXN = 100005,MAXK = 55;
const int INF = 1000005;
int N,K,M;
int arr[MAXN];
struct Node {
    bitset<MAXK> b;
    int L,R;  
}seg[4*MAXN];
unordered_map<int,int> treeKeys;

void build_tree(int v, int L, int R) {
    seg[v].L = L;
    seg[v].R = R;
    if (L == R) {
        treeKeys[L] = v;
        seg[v].b[arr[L]] = 1;
        return;
    }
    int mid = (L+R)/2;
    build_tree(v<<1,L,mid);
    build_tree(v<<1|1,mid+1,R);
    seg[v].b = seg[v*2].b | seg[v*2+1].b;
}

void updateBitset(int v) {
    if (v == 0) return;
    seg[v].b = seg[v<<1].b | seg[v<<1|1].b;
    updateBitset(v>>1);
}

void update(int v, int nxt) {
    seg[v].b.reset();
    seg[v].b[nxt] = 1;
    updateBitset(v>>1);
}

vector<int> countFullNodes(int v) {
    vector<int> nodes;
    if (seg[v].b.count() == K) {
        if (!(seg[v<<1].b.count() == K && seg[v<<1|1].b.count() == K))
            nodes.emplace_back(v);
        for (int i : countFullNodes(v<<1)) nodes.emplace_back(i);
        for (int i : countFullNodes(v<<1|1)) nodes.emplace_back(i);
    }
    return nodes;
}

vector<int> getSize(int v) {
    int sz = seg[v].R-seg[v].L+1;
    
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N); scan(K); scan(M);
    rep(i,0,N,1) scan(arr[i]);
    build_tree(1,0,N-1);
    int qType,idx,val;
    rep(i,0,M,1) {
        scan(qType);
        if (qType == 1) {
            scan(idx); --idx;
            scan(val);
            update(treeKeys[idx],val);
        }
        else {
            vector<int> potNodes = countFullNodes(1);
            if (potNodes.size() == 0) {
                cout << -1 << endl;
            }
            else {

            }
        }
    }


    
}