#include <bits/stdc++.h>
using namespace std;

int res(vector<vector <int> > graph, int p, int q, int n) {
    bool checked[1000000];
    for (int i = 0; i < n; i++) {
        checked[i] = false;
    }
    checked[p] = true;
    queue<int> eraser;
    eraser.push(p);
    while (!eraser.empty()) {
        for (int i = 0; i < graph[eraser.front()].size(); i++) {
            if (!checked[graph[eraser.front()][i]]) {
                eraser.push(graph[eraser.front()][i]);
                checked[graph[eraser.front()][i]] = true;
            }
        }
        eraser.pop();           
    }
    if (checked[q]) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector <int> > graph;
    for (int i = 0; i < n; i++) {
        vector<int> opti;
        graph.push_back(opti);
    }  
    int x,y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
    }
    int p,q;
    cin >> p >> q;
    p--; q--;
    if (res(graph,p,q,n) == 1) {
        cout << "yes" << endl;
    }
    else if (res(graph,q,p,n) == 1) {
        cout << "no" << endl;
    }  
    else {
        cout << "unknown" << endl;
    }
    
}