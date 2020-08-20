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
int t,m,n,g;
const int MAXN = 2005;
int dist[MAXN];
bitset<MAXN> bset;
vector<pair<int,int>> graph[MAXN];


int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    memset(dist,1,sizeof(dist));
    scan(t); scan(n); scan(m); scan(g); 
    int val;
    rep(i,0,g,1) {
        scan(val);
        bset[val] = 1;
    }
    int a,b,d;
    rep(i,0,m,1) {
        scan(a); scan(b); scan(d);
        graph[a].push_back({b,d});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    while (!pq.empty()) {
        int curTime = pq.top().f, node = pq.top().s;
        pq.pop();
        if (curTime <= dist[node]) {
            rep(i,0,graph[node].size(),1) {
                int travTime = graph[node][i].s, nxt = graph[node][i].f;
                if (travTime + curTime <= t && dist[nxt] > travTime + curTime) {
                    pq.push({dist[nxt] = travTime + curTime, nxt});
                }
            }
        }
    }
    int tot = 0;
    rep(i,1,n+1,1) {
        if (bset[i] && dist[i] <= t) ++tot;
    }
    printf("%d\n",tot);
}