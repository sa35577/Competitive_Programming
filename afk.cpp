#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int l,w;
    int ex,ey,sx,sy;
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    for (int dragren = 0; dragren < t; dragren++) {
        cin >> l >> w;
        string arr[w];
        for (int i = 0; i < w; i++) {
            cin >> arr[i];
            for (int j = 0; j < l; j++) {
                if (arr[i][j] == 'C') {
                    sy = i;
                    sx = j;
                }
                else if (arr[i][j] == 'W') {
                    ey = i;
                    ex = j;
                }
            }
        }
    
        int dp[w][l];
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < l; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        dp[sy][sx] = 0;
        q.push({0,sy * l + sx});
        while (!q.empty()) {
            auto cur = q.top();
            if (cur.first < 60) {
                int cx = cur.second % l;
                int cy = (cur.second - cx) / l;
                if (cy > 0) {
                    if (arr[cy-1][cx] != 'X' && dp[cy-1][cx] > cur.first + 1) {
                        dp[cy-1][cx] = cur.first + 1;
                        q.push({dp[cy-1][cx], cur.second - l});
                    }
                }
                if (cy < w-1) {
                    if (arr[cy+1][cx] != 'X' && dp[cy+1][cx] > cur.first + 1) {
                        dp[cy+1][cx] = cur.first + 1;
                        q.push({dp[cy+1][cx],cur.second + l});
                    }
                }
                if (cx > 0) {
                    if (arr[cy][cx-1] != 'X' && dp[cy][cx-1] > cur.first + 1) {
                        dp[cy][cx-1] = cur.first + 1;
                        q.push({dp[cy][cx-1],cur.second-1});
                    }
                }
                if (cx < l - 1) {
                    if (arr[cy][cx+1] != 'X' && dp[cy][cx+1] > cur.first + 1) {
                        dp[cy][cx+1] = cur.first + 1;
                        q.push({dp[cy][cx+1],cur.second+1});
                    }
                }

            }
            q.pop();
        }
        if (dp[ey][ex] >= 60) cout << "#notworth" << "\n";
        else cout << dp[ey][ex] << "\n";

    }

}