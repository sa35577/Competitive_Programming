#include <bits/stdc++.h>
using namespace std;

short int diff_grid[10005][10005] = {};
int main() {
    int N, M;
    cin >> N >> M;
    int x1, y1, x2, y2, w, h;
    for (int aa = 0; aa < M; aa++) {
        cin >> x1 >> y1 >> w >> h;
        x2 = x1+w-1;
        y2 = y1+h-1;
        diff_grid[x1][y1] += 1;
        diff_grid[x2+1][y1] -= 1;
        diff_grid[x1][y2+1] -= 1;
        diff_grid[x2+1][y2+1] += 1;

    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i > 0) diff_grid[i][j] += diff_grid[i-1][j];
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (j > 0) {
                diff_grid[i][j] += diff_grid[i][j-1];
                diff_grid[i][j] %= 2;
            }
        }
    }
    unsigned long long tot = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(diff_grid[i][j]) % 2 == 1) {
                tot++;
            }
        }
    }
    cout << tot << "\n";
    
    
}