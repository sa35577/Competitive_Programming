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

template<typename T> struct BIT {
    vector<vector<T>> bit;
    int len;
    void init(int sz) {
        bit.resize(sz+1);
        rep(i,0,sz+1,1) bit[i].resize(sz+1);
        len = sz;
    }
    T query(int x, int y) {
        T res = 0;
        for (; x > 0; x -= (x&-x)) {
            for (int idx = y; idx > 0; idx -= (idx&-idx)) {
                res += bit[x-1][idx-1];
            }
        }
        return res;
    }
    T query(int v1, int v2, int v3, int v4) {
        return query(v3+1,v4+1)-query(v3+1,v2)-query(v1,v4+1)+query(v1,v2);
    }
    void update(int x, int y, int val) {
        for (; x <= len; x += (x&-x)) {
            for (int idx = y; idx <= len; idx += (idx&-idx)) {
                bit[x-1][idx-1] += val;
            }
        }
    }
} ;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int ins,v1,v2,v3,v4;
    BIT<int> bit;
    while (1) {
        cin >> ins;
        if (ins == 0) {
            cin >> v1;
            bit.init(v1);
        }
        else if (ins == 1) {
            cin >> v1 >> v2 >> v3;
            bit.update(v1+1,v2+1,v3);
        }
        else if (ins == 2) {
            cin >> v1 >> v2 >> v3 >> v4;
            printf("%d\n",bit.query(v1,v2,v3,v4)); 
        }
        else if (ins == 3) return 0;
    }
}

