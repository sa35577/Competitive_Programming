#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];

int main() {

    int r,c;
    while (true) {
        cin >> r >> c;
        if (r == 0 && c == 0) break;
        memset(arr,1,sizeof(arr));
        int rbombs,rnum,spot,perRow;
        cin >> rbombs;
        string s;
        for (int a = 0; a < rbombs; a++) {
            cin >> rnum >> perRow;
            for (int i = 0; i < perRow; i++) {
                cin >> spot;
                arr[rnum][spot] = -1;
            }

        }
        int sr,sc,er,ec;
        cin >> sr >> sc >> er >> ec;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> q;
        arr[sr][sc] = 0;
        q.push({0,{sr,sc}});
        while (!q.empty()) {
            pair<int,pair<int,int>> cur = q.top();
            int dist = cur.first, cr = cur.second.first, cc = cur.second.second;
            //left
            if (cc - 1 >= 0 && arr[cr][cc-1] != -1 && arr[cr][cc-1] > dist + 1) {
                arr[cr][cc-1] = dist + 1;
                q.push({dist+1,{cr,cc-1}});
            }
            //right
            if (cc + 1 < c && arr[cr][cc+1] != -1 && arr[cr][cc+1] > dist + 1) {
                arr[cr][cc+1] = dist + 1;
                q.push({dist+1,{cr,cc+1}});
            }
            //up
            if (cr - 1 >= 0 && arr[cr-1][cc] != -1 && arr[cr-1][cc] > dist + 1) {
                arr[cr-1][cc] = dist+1;
                q.push({dist+1,{cr-1,cc}});
            }
            //down
            if (cr + 1 < r && arr[cr+1][cc] != -1 && arr[cr+1][cc] > dist + 1) {
                arr[cr+1][cc] = dist+1;
                q.push({dist+1,{cr+1,cc}});
            }
            q.pop();
        }
        cout << arr[er][ec] << endl;

    }
    return 0;
}