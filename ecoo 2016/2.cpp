#include <bits/stdc++.h>
using namespace std;

int t[5];
int vals[5001];
bool memoi[1000005][5] = {};
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int bob = 0; bob < 10; bob++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> vals[i];
        }
        for (int i = 0; i < 5; i++) {
            cin >> t[i];
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 1000005; j++) {
                for (int k = 0; k < 5; k++) {
                    memoi[i][j] = false;
                }
            }
            priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
            pq.push({t[i],0});
            bool flag = false;
            while (!pq.empty()) {
                pair<int,int> cur = pq.top();
                pq.pop();
                int val = cur.first, ops = cur.second;
                if (val < 0 || ops >= 4 || memoi[val][ops]) continue;
                if (val == 0 && ops < 4) {
                    flag = true;
                    break;
                }
                else if (val > 0 && ops < 3) {
                    for (int i = 0; i < n; i++) {
                        if (val % vals[i] == 0) {
                            pq.push({val/vals[i],ops+1});
                        }
                        if (val - vals[i] >= 0) {
                            pq.push({val-vals[i],ops+1});
                        }
                    }
                }
                memoi[val][ops] = true;
            }
            if (flag) cout << "T";
            else cout << "F";
        }
        cout << "\n";

    }
}
