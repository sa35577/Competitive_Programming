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

int N,Q;
const int SZ = 5001,MAXN = 100005;
ll K;
ll arr[MAXN];
vector<bool> prms;



vector<bool> segmentedSieve(ll L, ll R) {
    ll limit = sqrt(R);
    vector<bool> mark(limit + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= limit; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) //all multiples before it have been accounted for
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) isPrime[j - L] = 0;
    if (L == 1 && isPrime[0]) isPrime[0] = 0;
    return isPrime;
}

struct Node {
    int lazy;
    bitset<SZ> b;
}seg[4*MAXN];

void build_tree(int v, int L, int R) {
    seg[v].lazy = 0;
    if (L == R) {
        seg[v].b[arr[L]-K] = 1;
        return;
    }
    int mid = (L+R)/2;
    build_tree(v*2,L,mid);
    build_tree(v*2+1,mid+1,R);
    seg[v].b = seg[v*2].b | seg[v*2+1].b;
}

void push_lazy(int v, int L, int R) {
    if (seg[v].lazy == 0) return;
    if (seg[v].lazy > 0) {
        seg[v].b <<= seg[v].lazy;
    }
    else {
        seg[v].b >>= abs(seg[v].lazy);
    }
    if (L == R) {
        seg[v].lazy = 0;
        return;
    }
      
    seg[v*2].lazy += seg[v].lazy;
    seg[v*2+1].lazy += seg[v].lazy;
    seg[v].lazy = 0;
    return;
}

bitset<SZ> query(int v, int QL, int QR, int L, int R) {
    push_lazy(v,L,R);
    if (QR < L || R < QL) return bitset<SZ>();
    if (QL <= L && R <= QR) {
        return seg[v].b;
    }
    int mid = (L+R)/2;
    return query(v*2,QL,QR,L,mid) | query(v*2+1,QL,QR,mid+1,R);
}

void update(int v, int UL, int UR, int val, int L, int R) {
    push_lazy(v,L,R);
    if (UR < L || R < UL) return;
    if (UL <= L && R <= UR) {
        seg[v].lazy += val;
        push_lazy(v,L,R);
        return;
    }
    int mid = (L+R)/2;
    update(v*2,UL,UR,val,L,mid);
    update(v*2+1,UL,UR,val,mid+1,R);
    seg[v].b = seg[v*2].b | seg[v*2+1].b;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    
    cin >> N >> Q >> K;
    rep(i,0,N,1) cin >> arr[i];
    
    build_tree(1,0,N-1);
    prms = segmentedSieve(K,K+5000);
    vector<ll> lst;
    repr(i,prms.size()-1,-1,1) {
        if (prms[i]) {
            lst.push_back(i);
        }
    }
    
    
    int qType,L,R,val;
    rep(i,0,Q,1) {
        
        cin >> qType >> L >> R;
        --L; --R;
        if (qType == 1) {
            bool flag = false;
            bitset<SZ> res = query(1,L,R,0,N-1);
            for (int x = 0; !flag && x < lst.size(); x++) {
                if (res[lst[x]]) {
                    cout << lst[x]+K << endl; flag = true;
                }
            }
            
            if (!flag) cout << -1 << endl;
        }
        else {
            cin >> val;
            update(1,L,R,val,0,N-1);
        }
    }
    
}