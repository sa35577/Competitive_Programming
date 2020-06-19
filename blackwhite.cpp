#include <bits/stdc++.h>
using namespace std;




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int diff_grid[N+1][N+1];
    int x,y,w,h;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> w >> h;
        diff_grid[y][x]++;
        diff_grid[y][x+w]--;
        diff_grid[y+h][x]--;
        diff_grid[y+h][x+w]++;

    }
    for (int j = 0; j < 10005; j++) {
        for (int i = 1; i < 10005; i++) {
            diff_grid[i][j] += diff_grid[i-1][j];
        }
    }
    int tot = 0;
    for (int i = 0; i < 10005; i++) {
        for (int j = 1; j < 10005; j++) {
            diff_grid[i][j] += diff_grid[i][j-1];
            if (diff_grid[i][j] % 2 == 1) tot++;

        }
    }
    for (int i = 0; i < N; i++) {
        if (diff_grid[i][0] % 2 == 1) tot++;
    }
    cout << tot << "\n";
    
    
    
    
}
 