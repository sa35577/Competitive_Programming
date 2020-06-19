#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> graph[20005];
int dist[20005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int kk =1; kk <=tc; kk++) {
        int n,m,s,t;
        cin >> n >> m >> s >> t;
        int a,b,length;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> length;
            graph[a].push_back({b,length});
            graph[b].push_back({a,length});
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        memset(dist,1,sizeof(dist));
        pq.push({0,s});
        dist[s] = 0;
        int cdist,cnode,edge,nnode;
        while (!pq.empty()) {
            pair<int,int> front = pq.top();
            pq.pop();
            cdist = front.first;
            cnode = front.second;
            if (cdist > dist[cnode]) continue;
            for (int i = 0; i < graph[cnode].size(); i++) {
                edge = graph[cnode][i].second;
                nnode = graph[cnode][i].first;
                if (dist[nnode] > dist[cnode] + edge) {
                    dist[nnode] = dist[cnode] + edge;
                    pq.push({dist[nnode],nnode});
                }
            }
        }
        if (dist[t] == dist[20004]) {
            cout << "Case #" << kk << ": unreachable\n";
        }
        else cout << "Case #" << kk << ": " << dist[t] << "\n";



        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }

    }
    return 0;
}