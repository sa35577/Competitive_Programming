#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


bool visited[1001][1001];
long long grid[1001][1001];
bool counted[1000005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n,m;
    cin >> n >> m;
    
    for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
        cin >> grid[i][j];
        visited[i][j] = false;
    }
    
    queue<pair<long long,long long>> q;
    q.push({1,1});
    bool done = 0;
    while (!q.empty()) {
        pair<long long,long long> cur = q.front();
        long long x = cur.first, y = cur.second;
        if (!counted[grid[x][y]]) {
            long long val = grid[x][y];
            if (val == m*n) {
                done = 1;
                break;
            }
            for (long long i = m; i >= 1 && n*i >= val; i--) {
                if (val % i == 0 && !visited[val/i][i]) {
                    q.push({val/i,i});
                    visited[val/i][i] = 1;

                }
            }
            for (long long i = n; i >= 1 && m*i >= val; i--) {
                if (val % i == 0 && !visited[i][val/i]) {
                    q.push({i,val/i});
                    visited[i][val/i] = 1;
                }
            }
            counted[val] = 1;
        }
        q.pop();
    }
    if (done) cout << "yes";
    else cout << "no";
    


}