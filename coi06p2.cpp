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

int N,E;
const int MAXN = 100005;
vector<int> graph[MAXN];
pii adj[MAXN];


int search(int node, int p) {

} 


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N); scan(E);
    int v1,v2;
    rep(i,1,E+1,1) {
        scan(v1); scan(v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        adj[i] = {v1,v2};
    }

    int q;
    scan(q);
    int qType,a,b,c,g1,g2;
    rep(query,0,q,1) {
        scan(qType);
        if (qType == 1) {
            scan(a); scan(b); scan(g1); scan(g2);
        }
        else if (qType == 2) {
            scan(a); scan(b); scan(c);

        }
    }

    
}