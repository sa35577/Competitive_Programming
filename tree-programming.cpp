#include <bits/stdc++.h>
using namespace std;
unsigned int n,m,Q;
vector<pair<unsigned int,unsigned int>> graph[50005];
unsigned int mnval[50005];
unordered_map<unsigned int,unsigned int> mp;


int main() {
    cin >> n >> m >> Q;
    unsigned int u,v,k;
    for (unsigned int i = 0; i < m; i++) {
        cin >> u >> v >> k;
        --u;--v;
        graph[u].push_back({v,k});
        graph[v].push_back({u,k});
    }
    unsigned int a,b;
    priority_queue<pair<unsigned int,unsigned int>,
    vector<pair<unsigned int,unsigned int>>,
    greater<pair<unsigned int,unsigned int>>> q;
    for (unsigned int qq = 0; qq < Q; qq++) {
        cin >> a >> b;
        --a;--b;/*
        if (mp.find(a*(n-1)+b) != mp.end()) {
            cout << mp[a*(n-1)+b] << endl;
            continue;
        }*/
        q.push({0,a});
        fill(mnval,mnval+10005,INT_MAX);
        mnval[a] = 0;
        while (!q.empty()) {
            pair<unsigned int,unsigned int> cur = q.top();
            unsigned int cval = cur.first, cnode = cur.second;
            unsigned int nval,nnode;
            for (unsigned int i = 0; i < graph[cnode].size(); i++) {
                nval = cval | graph[cnode][i].first;
                nnode = graph[cnode][i].second;
                if (mnval[nnode] > nval) {
                    mnval[nnode] = nval;
                    q.push({nval,nnode});
                }
            }
            q.pop();
        }
        cout << mnval[b] << endl;
        //mp[a*(n-1)+b] = mnval[b];
        //mp[b*(n-1)+a] = mnval[b];
    }


}