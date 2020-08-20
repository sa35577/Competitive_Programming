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

int N,K;
const int MAXN = 3005;
ll bit[MAXN][MAXN],arr[MAXN][MAXN];

void update(int x, int y, ll val) {
    for (; x <= N; x += (x&-x)) {
        for (int Y = y; Y <= N; Y += (Y&-Y)) {
            bit[x][Y] = max(bit[x][Y],val);
        }
    }
}

ll query(int x, int y) {
    ll res = 0;
    for (; x > 0; x -= (x&-x)) {
        for (int Y = y; Y > 0; Y -= (Y&-Y)) {
            res = max(res,bit[x][Y]);
        }
    }
    return res;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    ll sum = 0;
    cin >> N >> K;
    rep(i,1,N+1,1) {
        rep(j,N-i+1,N+1,1) cin >> arr[i][j]; //right alignment
    }
    
    repr(top,N,-1,1) {
        rep(i,1,N-top+1,1) {
            int x = N-i+1, y = i+top;
            update(x,y,arr[x][y]);
            if (N-x+1 >= K) sum += query(x+K-1,y);
        }
    }
    

    printf("%lld\n",sum);

}