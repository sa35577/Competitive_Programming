#include <bits/stdc++.h>
using namespace std;
#define p pair<int,int>

const int E = 0, N = 1, W = 2, S = 3;
int store[55][55];
int paths[55][55][4];



int main() {
    //ifstream fin("robot.in");
    //ofstream fout("robot.out");
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int r,c;
    while (true) {
        memset(paths,1,sizeof(paths));
        cin >> r >> c;
        if (r == 0 && c == 0) break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> store[i][j];
            }
        }
        for (int i = r-1; i >= 0; i--) {
            for (int j = c-1; j >= 0; j--) {
                if (store[i][j] == 1) {
                    store[i][j+1] = 1;
                    store[i+1][j] = 1;
                    store[i+1][j+1] = 1;
                    for (int k = 0; k < 4; k++) {
                        paths[i][j][k] = -1;
                        paths[i+1][j][k] = -1;
                        paths[i][j+1][k] = -1;
                        paths[i+1][j+1][k] = -1;
                    }
                }
            }
        }
        int sr,sc,er,ec;
        cin >> sr >> sc >> er >> ec;
        string sd;
        int sDirection;
        cin >> sd;
        if (sd == "east") {
            sDirection = E;
        }
        else if (sd == "north") {
            sDirection = N;
        }
        else if (sd == "west") {
            sDirection = W;
        }
        else if (sd == "south") {
            sDirection = S;
        }
        
        priority_queue<pair<p,p>,
        vector<pair<p,p>>,
        greater<pair<p,p>>> pq;
        paths[sr][sc][sDirection] = 0;
        pq.push({{0,sDirection},{sr,sc}});
        int dist,dir,cr,cc;
        while (!pq.empty()) {
            pair<p,p> front = pq.top();
            pq.pop();
            dist = front.first.first;
            dir = front.first.second;
            cr = front.second.first;
            cc = front.second.second;
            if (dist > paths[cr][cc][dir]) continue;

            if (paths[cr][cc][(dir+1)%4] > paths[cr][cc][dir] + 1) {
                paths[cr][cc][(dir+1)%4] = paths[cr][cc][dir] + 1;
                pq.push({{paths[cr][cc][(dir+1)%4],(dir+1)%4},{cr,cc}});
            }
            if (paths[cr][cc][(dir+2)%4] > paths[cr][cc][dir] + 2) {
                paths[cr][cc][(dir+2)%4] = paths[cr][cc][dir] + 2;
                pq.push({{paths[cr][cc][(dir+2)%4],(dir+2)%4},{cr,cc}});
            }
            if (paths[cr][cc][(dir+3)%4] > paths[cr][cc][dir] + 1) {
                paths[cr][cc][(dir+3)%4] = paths[cr][cc][dir] + 1;
                pq.push({{paths[cr][cc][(dir+3)%4],(dir+3)%4},{cr,cc}});
            }

            if (dir == E) {
                for (int i = 1; i <= 3; i++) {
                    if (cc + i < c && store[cr][cc+i] == 0) {
                        if (paths[cr][cc+i][dir] > paths[cr][cc][dir] + 1) {
                            paths[cr][cc+i][dir] = paths[cr][cc][dir] + 1;
                            pq.push({{paths[cr][cc+i][dir],dir},{cr,cc+i}});
                        }
                    }
                    else break;
                }
            }
            if (dir == W) {
                for (int i = 1; i <= 3; i++) {
                    if (cc - i > 0 && store[cr][cc-i] == 0) {
                        if (paths[cr][cc-i][dir] > paths[cr][cc][dir] + 1) {
                            paths[cr][cc-i][dir] = paths[cr][cc][dir] + 1;
                            pq.push({{paths[cr][cc-i][dir],dir},{cr,cc-i}});
                        }
                    }
                    else break;
                }
            }
            if (dir == N) {
                for (int i = 1; i <= 3; i++) {
                    if (cr - i > 0 && store[cr-i][cc] == 0) {
                        if (paths[cr-i][cc][dir] > paths[cr][cc][dir] + 1) {
                            paths[cr-i][cc][dir] = paths[cr][cc][dir] + 1;
                            pq.push({{paths[cr-i][cc][dir],dir},{cr-i,cc}});
                        }
                    }
                    else break;
                }
            }
            if (dir == S) {
                for (int i = 1; i <= 3; i++) {
                    if (cr + i < r && store[cr+i][cc] == 0) {
                        if (paths[cr+i][cc][dir] > paths[cr][cc][dir] + 1) {
                            paths[cr+i][cc][dir] = paths[cr][cc][dir] + 1;
                            pq.push({{paths[cr+i][cc][dir],dir},{cr+i,cc}});
                        }
                    }
                    else break;
                }
            }
            

        }
        int mn = INT_MAX;
        for (int i = 0; i < 4; i++) {
            mn = min(mn,paths[er][ec][i]);
        }
        if (mn == paths[54][54][0] || mn == -1) {
            cout << -1 << endl;
        }
        else {
            cout << mn << endl;
        }

    }
    return 0;
}