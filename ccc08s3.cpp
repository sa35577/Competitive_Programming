#include <bits/stdc++.h>
using namespace std;

string config[21];
int minDist[21][21];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int r,c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) cin >> config[i];
        memset(minDist,1,sizeof(minDist));
        if (config[0][0] == '*') {
            cout << "-1\n";
            continue;
        }
        minDist[0][0] = 1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        while (!pq.empty()) {
            int dist = pq.top().first;
            int y = pq.top().second.first, x = pq.top().second.second;
            pq.pop();
            if (minDist[y][x] < dist) continue;
            if (config[y][x] == '+') {
                //east
                if (x < c-1 && config[y][x+1] != '*' && minDist[y][x+1] > dist + 1) {
                    minDist[y][x+1] = dist + 1;
                    pq.push({dist+1,{y,x+1}});
                }
                //west
                if (x > 0 && config[y][x-1] != '*' && minDist[y][x-1] > dist + 1) {
                    minDist[y][x-1] = dist + 1;
                    pq.push({dist+1,{y,x-1}});
                }
                //north
                if (y < r-1 && config[y+1][x] != '*' && minDist[y+1][x] > dist + 1) {
                    minDist[y+1][x] = dist + 1;
                    pq.push({dist+1,{y+1,x}});
                }
                //south
                if (y > 0 && config[y-1][x] != '*' && minDist[y-1][x] > dist + 1) {
                    minDist[y-1][x] = dist + 1;
                    pq.push({dist+1,{y-1,x}});
                }
            }
            else if (config[y][x] == '-') {
                if (x < c-1 && config[y][x+1] != '*' && minDist[y][x+1] > dist + 1) {
                    minDist[y][x+1] = dist + 1;
                    pq.push({dist+1,{y,x+1}});
                }
                if (x > 0 && config[y][x-1] != '*' && minDist[y][x-1] > dist + 1) {
                    minDist[y][x-1] = dist + 1;
                    pq.push({dist+1,{y,x-1}});
                }
            }
            else if (config[y][x] == '|') {
                if (y < r-1 && config[y+1][x] != '*' && minDist[y+1][x] > dist + 1) {
                    minDist[y+1][x] = dist + 1;
                    pq.push({dist+1,{y+1,x}});
                }
                if (y > 0 && config[y-1][x] != '*' && minDist[y-1][x] > dist + 1) {
                    minDist[y-1][x] = dist + 1;
                    pq.push({dist+1,{y-1,x}});
                }
            }
        }
        if (minDist[r-1][c-1] == 16843009) {
            cout << "-1\n";
        }
        else {
            cout << minDist[r-1][c-1] << "\n";
        }
    }
}