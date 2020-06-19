#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<vector<int> > graph;
    for (int i = 0; i < N; i++)
        graph.push_back({});
    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (find(graph[b-1].begin(),graph[b-1].end(),a-1) == graph[b-1].end())
            graph[b-1].push_back(a-1);
    }
    bool flag = false;
    bool visited[n];
    
    for (int k = 0; k < n; i++) {
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        



    }

}
