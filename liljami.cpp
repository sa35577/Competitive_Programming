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
const int MAXN = 1000005;
int pre[MAXN],arr[MAXN];
int val;



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N >> K;
    rep(i,0,K,1) {
        cin >> val;
        ++arr[++val];
    }
    rep(i,1,N+1,1) {
        pre[i] = pre[i-1] + arr[i];
    }
    int Q;
    cin >> Q;
    int a,b;
    rep(i,0,Q,1) {
        cin >> a >> b;
        ++a; ++b;
        cout << pre[b] - pre[a-1] << endl;
    }
}