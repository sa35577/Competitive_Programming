#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<pair<int,int>> graph[MAXN];
int minDist[MAXN];

int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    while (M--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    deque<pair<int,int>> q;
    memset(minDist,1,sizeof(minDist));
    q.push_back({1,0});
    minDist[1] = 0;
    while (!q.empty()) {
        int node = q.front().first, dist = q.front().second;
        q.pop_front();
        if (dist <= minDist[node]) {
            for (pair<int,int> nxt : graph[node]) {
                if (minDist[nxt.first] > dist + nxt.second) {
                    minDist[nxt.first] = dist + nxt.second;
                    q.push_back({nxt.first,minDist[nxt.first]});
                }
            }
        }
    }
    printf("%d\n",minDist[N]);
}