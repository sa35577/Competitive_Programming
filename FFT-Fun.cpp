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
//const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

struct Pair {
    int xPow,yPow;
};
const ull MOD = 998244353;

ull fastPow(int base, int power) {
    ull res = 1;
    if (power == 1) return res;
    if (power % 2 == 1) {
        res *= (ull)base;
        res = res % MOD;
    }
    int hlf = fastPow(base,power/2);
    res = (res*hlf*hlf)%MOD;
    return res;
}
ull compWays(int m, int n) {
    
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int tc;
    ull x,y;
    ull T;
    scan(tc);
    rep(i,0,tc,1) {
        scan(x); scan(y);
        scan(T);
        if (T == 1) {
            cout << x << endl;
            return;
        }
        else if (T == 2) {
            cout << y << endl;
            return;
        }
        int exp = (int)(log10(y)/log10(x));
        int curY = 1;

        
    }
}