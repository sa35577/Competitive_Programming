#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define p pair<int,int>
const int MAXN = 4001,MAXFAC=16000005;
bool vis[MAXN][MAXN];
vector<p> pairs[MAXFAC];
vector<vector<int>> arr;

void search(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;
    vector<p> factorPairs = pairs[arr[i][j]];
    pairs[arr[i][j]].clear();
    for (p cur : factorPairs) {
        search(cur.first,cur.second);
    }
}

bool can_escape(int M, int N, vector<vector<int>> v) {
    int m = M, n = N;
    arr = v;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            pairs[i*j].emplace_back(make_pair(i,j));
        }
    }
    search(1,1);
    return vis[M][N];
}