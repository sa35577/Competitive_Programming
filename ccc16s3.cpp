#include <bits/stdc++.h>
using namespace std;

queue<int> Q;


vector<int> tree[100005];
int main() {
    int n,m;
    cin >> n >> m;
    int pho[m];
    for (int i = 0; i < m; i++) {
        cin >> pho[i];
    }
    int a,b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    bool found;
    for (int i = 0; i < n; i++) {
        found = 0;
        for (int j = 0; j < m; i++) {
            if (i == pho[j]) {
                found = 1;
                continue;
            }
        }
        if (tree[i].size() == 1 || !found) {
            tree[tree[i][0]].erase(find(tree[tree[i][0]].begin(),tree[tree[i][0]].end(),i));
            tree[i].clear();
        }
    }


}