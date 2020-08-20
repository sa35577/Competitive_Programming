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

struct Edge {
    int v,t,h;  
    Edge(int V, int T, int H) {
        v = V;
        t = T;
        h = H;
    }
};
int k,m,n;
const int MAXN = 2005,MAXK=205;
int sta,des;
vector<Edge> graph[MAXN];
bitset<MAXN> vis;
int dist[MAXN][MAXK];




int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(k); scan(n); scan(m); 
    rep(i,0,MAXN,1) rep(j,0,MAXK,1) dist[i][j] = 100000000;
    int a,b,t,h;
    rep(i,0,m,1) {
        scan(a); scan(b); scan(t); scan(h);
        graph[a].push_back(Edge(b,t,h));
        graph[b].push_back(Edge(a,t,h));
    }
    scan(sta); scan(des); 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[sta][0] = 0;
    vis[sta] = 1;
    pq.push({0,sta});
    while (!pq.empty()) {
        pair<int,int> cur = pq.top();
        pq.pop();
        int node = cur.s;   
        vis[node] = 0;
        rep(i,0,graph[node].size(),1) {
            for (int j = 0; j+graph[node][i].h < k; j++) {
                if (dist[node][j] + graph[node][i].t < dist[graph[node][i].v][j+graph[node][i].h]) {
                    dist[graph[node][i].v][j+graph[node][i].h] = dist[node][j] + graph[node][i].t;
                    if (!vis[graph[node][i].v]) {
                        vis[graph[node][i].v] = 1;
                        pq.push({dist[node][j] + graph[node][i].t,graph[node][i].v});
                    }

                }
            }
        }
        
    }

    int mn = 100000000;
    rep(i,0,k,1) {
        mn = min(mn,dist[des][i]);
    }
    if (mn == 100000000) cout << -1 << endl;
    else cout << mn << endl;


}