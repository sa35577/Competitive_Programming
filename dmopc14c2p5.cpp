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
const int MAXN = 1000005;
vector<int> graph[MAXN];
ld prob[MAXN];
bitset<MAXN> leaf;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    rep(i,0,MAXN,1) { prob[i] = 0; leaf[i] = 1; }
    scan(N);
    scan(M);
    int par,chi;
    rep(i,0,M,1) {
        scan(par);
        scan(chi);
        leaf[par] = 0;
        graph[par].push_back(chi);
    }
    prob[1] = 1.0;
    rep(i,1,N+1,1) {
        if (leaf[i])
            printf("%.10Lf\n",prob[i]);
        
        else {
            
            rep(j,0,graph[i].size(),1) {
                prob[graph[i][j]] += prob[i]/((ld)graph[i].size()); 
            }
        }
    }


}