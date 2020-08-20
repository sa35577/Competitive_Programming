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
unsigned int n,t,d;
const unsigned int MAXN = 5005;
unsigned int graph[MAXN][MAXN];
vector<pair<unsigned int,unsigned int>> grph[MAXN];
unsigned int vis[MAXN];
pair<unsigned int,unsigned int> cost[MAXN];
bitset<MAXN> b[MAXN];

void ship() {
    priority_queue<pair<unsigned int,unsigned int>,vector<pair<unsigned int,unsigned int>>,greater<pair<unsigned int,unsigned int>>> pq;
    vis[d] = 0;
    pq.push({d,0});
    while (!pq.empty()) {
        pair<unsigned int,unsigned int> cur = pq.top();
        pq.pop();
        unsigned int v = cur.f;
        unsigned int dist=cur.s;
        if (dist <= vis[v]) {
            //move
            for (unsigned int i = 0; i < grph[v].size(); i++) {
                unsigned int nxt = grph[v][i].f;
                if (graph[v][nxt] + dist < vis[nxt]) {
                    vis[nxt] = graph[v][nxt] + dist;
                    pq.push({nxt,vis[nxt]});
                }
                
            }
        }
    }
}

int main() {
    
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    
    scan(n); scan(t);
    unsigned int v1,v2;
    unsigned int w;
    for (unsigned int i = 0; i < t; i++) {
        scan(v1); scan(v2); scan(w);
        if (b[v1][v2] && v1 != v2) {
            graph[v1][v2] = min(graph[v1][v2],w);
            graph[v2][v1] = min(graph[v2][v1],w);
        }
        else {
            graph[v1][v2] = w;
            graph[v2][v1] = w;
            b[v1][v2] = 1;
            b[v2][v1] = 1;
        }
    }
    
    for (unsigned int i = 1; i <= n; i++) {
        for (unsigned int j = 1; j <= n; j++) {
            if (b[i][j]) {
                grph[i].push_back({j,graph[i][j]});
            }
        }
    }
    unsigned int k;
    scan(k);
    unsigned int z;
    unsigned int pz;
    unsigned int tot = UINT_MAX;
    
    for (unsigned int i = 0; i < k; i++) {
        scan(z); scan(pz);
        cost[i] = {z,pz};
    }
    scan(d);
    
    for (unsigned int i = 0; i <= n; i++)
        vis[i] = UINT_MAX;
    
    ship();
    for (unsigned int i = 0; i < k; i++)
        tot = min(tot,vis[cost[i].f]+cost[i].s);
    
    cout << tot << endl;   
}