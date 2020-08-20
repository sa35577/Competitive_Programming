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
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int N,M;
const int MAXN = 100005;
ll arr[MAXN];
struct BIT {
    vector<ll> bit;
    void resize(int sz) {
        bit.resize(sz+1);
    }
    void init(ll arr[]) {
        rep(i,1,bit.size()+1,1) {
            bit[i] += arr[i];
            if (i + (i&-i) <= bit.size()) {
                bit[i + (i&-i)] += bit[i];
            }
        }

    }
    void update(int idx, int val) {
        while (idx <= bit.size()) {
            bit[idx] += val;
            idx += (idx&-idx);
        }
    }
    ll query(int idx) {
        ll val = 0;
        while (idx > 0) {
            val += bit[idx];
            idx -= (idx&-idx);
        }
        return val;
    }
    ll query(int lo, int hi) {
        return query(hi)-query(lo-1);
    }
} bit,diff;

/*
template<int mn, typename T> struct BIT {
    vector<T> bit(mn+1);
    T query(int n) {
        T ret = 0;
        for (; n >= 0; n -= (n&-n)) ret += bit[n];
        return ret;
    }
    T query(int l, int r) { return query(r) - query(l-1); }
    void update(int n, T v) { for (; n <= bit.size(); n += (n&-n)) bit[n] += v; }
} ;  
*/

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N >> M;
    diff.resize(MAXN<<1);
    rep(i,1,N+1,1) {
        cin >> arr[i];
        diff.update(arr[i],1);
    }
    bit.resize(N);
    bit.init(arr);
    char op;
    int v1,v2;
    rep(i,0,M,1) {
        cin >> op;
        if (op == 'C') {
            cin >> v1 >> v2;
            diff.update(arr[v1],-1);
            diff.update(v2,1);
            bit.update(v1,v2-arr[v1]);
            arr[v1] = v2;   

        }
        else if (op == 'S') {
            cin >> v1 >> v2;
            cout << bit.query(v1,v2) << endl;
        }
        else if (op == 'Q') {
            cin >> v1;
            cout << diff.query(v1) << endl;

        }
    }

    

}