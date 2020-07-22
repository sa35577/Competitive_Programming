#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;

    ll arr[100005][2];
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) cin >> arr[i][j];
        q.push({arr[i][0],arr[i][1]});
    }
    
    double mx = 0,sp;
    pair<int,int> prev = q.top();
    q.pop();
    pair<int,int> cur;
    while (!q.empty()) {
        cur = q.top();
        int x1 = prev.first, y1 = prev.second, x2 = cur.first, y2 = cur.second;
        sp = (double)(y2-y1)/(x2-x1);
        if (sp < 0) sp *= (-1);
        if (mx < sp) mx = sp;
        prev = cur;
        q.pop();
    }
    //cout << mx; 
    printf("%.7f",mx);
}