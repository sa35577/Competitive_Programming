#include <bits/stdc++.h>
using namespace std;


vector<pair<long long,long long>> graph[105];
int main() {
    //ifstream fin("mice-and-maze.in");
    //ofstream fout("mice-and-maze.out");
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long tc;
    cin >> tc;
    for (long long kk = 0; kk < tc; kk++) {
        long long e,eNode,t,connections;
        cin >> e >> eNode >> t >> connections;
        long long a,b,dist;
        for (long long i = 0; i < connections; i++) {
            cin >> a >> b >> dist;
            graph[a].push_back({b,dist});
        }
        long long ts[105],ont=0;
        for (long long s = 1; s <= e; s++) {
            if (s == eNode) {
                ++ont;
                continue;
            }
            fill(ts,ts+105,1e9);
            ts[s] = 0;
            priority_queue<pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>> pq;
            pq.push({0,s});
            long long cdist,cnode,edge,nnode;
            while (!pq.empty()) {
                pair<long long,long long> front = pq.top();
                pq.pop();
                cdist = front.first, cnode = front.second;
                if (cdist > t) continue;
                if (cdist <= t && cnode == eNode) {
                    ts[eNode] = cdist;
                    break;
                }
                for (long long i = 0; i < graph[cnode].size(); i++) {
                    edge = graph[cnode][i].second;
                    nnode = graph[cnode][i].first;
                    if (ts[nnode] > cdist + edge) {
                        ts[nnode] = cdist + edge;
                        pq.push({ts[nnode],nnode});
                    }
                }
            }
            if (ts[eNode] <= t) ++ont;
        }
        cout << ont << endl;
        if (kk < tc-1) cout << endl;
        for (int i = 0; i < 105; i++) {
            graph[i].clear();
        }
    }
    return 0;
}