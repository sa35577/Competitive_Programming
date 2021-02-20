#include <bits/stdc++.h>
using namespace std;


const int MAXN = 10005;
vector<int> graph[MAXN];
int minDist[MAXN];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M,x;
    for (int i = 1; i <= N; i++) {
        minDist[i] = 1000000;
        cin >> M;
        while (M--) {
            cin >> x;
            graph[i].push_back(x);
        }
    }
    pq.push({1,1});
    minDist[1] = 1;
    while (!pq.empty()) {
        int dist = pq.top().first, node = pq.top().second;
        pq.pop();
        if (dist > minDist[node]) continue;
        for (int nxt : graph[node]) {
            if (minDist[nxt] > dist + 1) {
                minDist[nxt] = dist + 1;
                pq.push({minDist[nxt],nxt});
            }
        }
    }
    bool allVis = true;
    int minPath = INT_MAX;
    for (int i = 1; i <= N; i++) {
        if (minDist[i] == 1000000) {
            allVis = false;
        }
        if (graph[i].size() == 0) {
            minPath = min(minPath,minDist[i]);
        }
    }
    if (allVis) cout << "Y\n";
    else cout << "N\n";
    cout << minPath << "\n";
}