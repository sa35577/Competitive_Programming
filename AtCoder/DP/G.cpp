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


/*---END OF TEMPLATE---*/
vector<int> in[100005],out[100005];
int dist[100005];


int dfs(int node) {
    int d = 0;
    rep(i,0,out[node].size(),1) {
        if (dist[out[node][i]] == -1) {
            d = max(d,1+dfs(out[node][i]));
        }
        else {
            d = max(d,1+dist[out[node][i]]);
        }
    }
    return dist[node] = d;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    rep(i,0,100005,1) dist[i] = -1;
    int n,m;
    cin >> n >> m;
    int sta,fin;
    rep(i,0,m,1) {
        cin >> sta >> fin;
        out[sta].push_back(fin);
        in[fin].push_back(sta);
    }
    vector<int> startNodes;
    rep(i,1,n+1,1) {
        if (out[i].size() > 0 && in[i].size() == 0) {
            startNodes.push_back(i);
        }
    }


    int mx = -1;

    for (int startNode : startNodes) {
        if (mx < dfs(startNode)) mx = dfs(startNode);
    }
    cout << mx << endl;

    



}