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

const int MAXN = 1505;
queue<p> q;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    q.push({0,0});
    int N,H;
    scan(N);
    scan(H);
    memset(A,1,sizeof(A));
    rep(i,0,N,1) {
        rep(j,0,N,1) {
            scan(A[i][j]);
            vis[i][j] = 0;
        } 
    }
    vis[0][0] = 1;
    while (!q.empty()) {
        p cur = q.front();
        q.pop();
        
        if (cur.f == cur.s && cur.f == N-1) break;
        if (cur.f < N-1) {
            if (!vis[cur.f+1][cur.s] && abs(A[cur.f+1][cur.s]-A[cur.f][cur.s]) <= H) {
                vis[cur.f+1][cur.s] = 1;
                q.push({cur.f+1,cur.s});
            }
        }
        if (cur.s < N-1) {
            if (!vis[cur.f][cur.s+1] && abs(A[cur.f][cur.s+1]-A[cur.f][cur.s]) <= H) {
                vis[cur.f][cur.s+1] = 1;
                q.push({cur.f,cur.s+1});
            }
        }
        if (cur.f > 0) {
            if (!vis[cur.f-1][cur.s] && abs(A[cur.f-1][cur.s]-A[cur.f][cur.s]) <= H) {
                vis[cur.f-1][cur.s] = 1;
                q.push({cur.f-1,cur.s});
            }
        }
        if (cur.s > 0) {
            if (!vis[cur.f][cur.s-1] && abs(A[cur.f][cur.s-1]-A[cur.f][cur.s]) <= H) {
                vis[cur.f][cur.s-1] = 1;
                q.push({cur.f,cur.s-1});
            }
        }
    }
    cout << (vis[N-1][N-1] ? "yes" : "no");



}