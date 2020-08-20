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
struct BIT {
    vector<vector<vector<ll>>> bit,arr;
    int len;

    void init(int sz) {
        bit.resize(sz+1); arr.resize(sz+1);
        for (auto &b2 : bit) {
            b2.resize(sz+1);
            for (auto &b3 : b2) {
                b3.resize(sz+1);
                for (int i : b3) i = 0;
            }
        }
        for (auto &b2 : arr) {
            b2.resize(sz+1);
            for (auto &b3 : b2) {
                b3.resize(sz+1);
                for (int i : b3) i = 0;
            }
        }
        len = sz;

    }
    ll query(int x, int y, int z) {
        ll res = 0;
        for (; x > 0; x -= (x&-x)) {
            for (int Y = y; Y > 0; Y -= (Y&-Y)) {
                for (int Z = z; Z > 0; Z -= (Z&-Z)) {
                    res += bit[x-1][Y-1][Z-1];
                }
            }
        }
        return res;
    }

    ll query(int v1, int v2, int v3, int v4, int v5, int v6) {
        ll q1 = query(v4,v5,v6);
        ll q2 = query(v1-1,v5,v6) + query(v4,v2-1,v6) + query(v4,v5,v3-1);
        ll q3 = query(v4,v2-1,v3-1) + query(v1-1,v5,v3-1) + query(v1-1,v2-1,v6);
        ll q4 = query(v1-1,v2-1,v3-1);
        return q1 - q2 + q3 - q4;
    }

    void update(int x, int y, int z, ll nw) {
        ll val = nw - arr[x][y][z];
        arr[x][y][z] = nw;
        for (; x <= len; x += (x&-x)) {
            for (int Y = y; Y <= len; Y += (Y&-Y)) {
                for (int Z = z; Z <= len; Z += (Z&-Z)) {
                    bit[x-1][Y-1][Z-1] += val;
                }
            }
        }
    }


} ;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int N,Q;
    cin >> N >> Q;
    BIT bit;
    bit.init(N);
    char op;
    int v1,v2,v3,v4,v5,v6;
    ll v4Dash;
    ll ans = 0;
    rep(i,0,Q,1) {
        cin >> op;
        cin >> v1 >> v2 >> v3;
        if (op == 'C') {
            cin >> v4Dash;
            bit.update(v1,v2,v3,v4Dash);
        }
        else if (op == 'S') {
            cin >> v4 >> v5 >> v6;
            ans += bit.query(v1,v2,v3,v4,v5,v6);
        }
    }
    printf("%lld\n",ans);
}