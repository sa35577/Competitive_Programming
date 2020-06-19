#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];
int dist[1005][1005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 0; tt < tc; tt++) {
        int r,c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> arr[i][j];
                dist[i][j] = 1e7;
            }
        }
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> q;
        q.push({arr[0][0],{0,0}});
        dist[0][0] = arr[0][0];
        while (!q.empty()) {
            pair<int,pair<int,int>> front = q.top();
            q.pop();
            int d = front.first, cr = front.second.first, cc = front.second.second;
            if (d > dist[cr][cc]) continue;
            if (cr - 1 >= 0 && dist[cr][cc] + arr[cr-1][cc] < dist[cr-1][cc]) {
                dist[cr-1][cc] = dist[cr][cc] + arr[cr-1][cc];
                q.push({dist[cr-1][cc],{cr-1,cc}});
            }
            if (cr + 1 < r && dist[cr][cc] + arr[cr+1][cc] < dist[cr+1][cc]) {
                dist[cr+1][cc] = dist[cr][cc] + arr[cr+1][cc];
                q.push({dist[cr+1][cc],{cr+1,cc}});
            }
            if (cc - 1 >= 0 && dist[cr][cc] + arr[cr][cc-1] < dist[cr][cc-1]) {
                dist[cr][cc-1] = dist[cr][cc] + arr[cr][cc-1];
                q.push({dist[cr][cc-1],{cr,cc-1}});
            }
            if (cc + 1 < c && dist[cr][cc] + arr[cr][cc+1] < dist[cr][cc+1]) {
                dist[cr][cc+1] = dist[cr][cc] + arr[cr][cc+1];
                q.push({dist[cr][cc+1],{cr,cc+1}});
            }
        }
        cout << dist[r-1][c-1] << "\n";
    }
}