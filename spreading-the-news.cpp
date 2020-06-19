#include <bits/stdc++.h>
using namespace std;
int e;
vector<int> graph[2500];


void search(int start) {
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    q.push({0,start});
    
    bool visited[2500];
    int boom[10000];
    fill(visited,visited+e,false);
    fill(boom,boom+10000,0);
    visited[start] = 1;
    while (!q.empty()) {
        pair<int,int> cur = q.top();
        int day = cur.first, emp = cur.second;
        ++boom[day];
        for (int i : graph[emp]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push({day+1,i});
            }
        }
        q.pop();
    }
    int mx = -1, freq = 0;
    for (int i = 1; i < 10000; i++) {
        if (boom[i] > mx) {
            freq = i;
            mx = boom[i];
        }
    }
    cout << mx << " " << freq << endl;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); 
    cin >> e;
    int n,val;
    for (int i = 0; i < e; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> val;
            graph[i].push_back(val);
        }
    }
    int t;
    cin >> t;
    int start;
    for (int k = 0; k < t; k++) {
        cin >> start;
        if (graph[start].size() == 0) {
            cout << 0 << endl;
        }
        else {
            search(start);
        }
    }


}