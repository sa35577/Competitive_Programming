#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define p pair<int,int>
const int MAXN = 1001,MAXFAC=10000001;
bool vis[MAXN][MAXN];
int arr[MAXN][MAXN];
vector<p> pairs[MAXFAC];

void search(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;
    vector<p> factorPairs = pairs[arr[i][j]];
    pairs[arr[i][j]].clear();
    for (p cur : factorPairs) {
        search(cur.first,cur.second);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            pairs[(i+1)*(j+1)].push_back(make_pair(i,j));
        }
    }
    search(0,0);
    if (vis[n-1][m-1]) cout << "yes\n";
    else cout << "no\n";
}