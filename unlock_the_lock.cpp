#include <bits/stdc++.h>
using namespace std;

int shortest[10005];
int arr[15];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int l,u,r,runs=0;
    while (true) {
        cin >> l >> u >> r;
        if (l + u + r == 0) break;
        ++runs;
        memset(shortest,1,sizeof(shortest));
        for (int i = 0; i < r; i++) cin >> arr[i];
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        pq.push({0,l});
        shortest[l] = 0;
        int dist,val;
        while (!pq.empty()) {
            pair<int,int> front = pq.top();
            pq.pop();
            dist = front.first;
            val = front.second;
            if (dist > shortest[val]) continue;
            for (int i = 0; i < r; i++) {
                if (shortest[(val+arr[i])%10000] > shortest[val] + 1) {
                    shortest[(val+arr[i])%10000] = shortest[val] + 1;
                    pq.push({shortest[(val+arr[i])%10000],(val+arr[i])%10000});
                }
            }
        }
        cout << "Case " << runs << ": ";
        if (shortest[u] == shortest[10004]) cout << "Permanently Locked\n";
        else cout << shortest[u] << "\n";
    }
    return 0;
}