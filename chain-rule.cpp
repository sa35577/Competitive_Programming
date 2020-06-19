#include <bits/stdc++.h>
using namespace std;

int N,M;
//First is the distance, second is the city
vector <pair<int,int>> routes[100005];
int main() {
    cin >> N >> M;
    int A,B,t;
    int arr[100005],ans[100005];
    for (int i = 0; i < N; i++) {
        arr[i] = 999999;
        ans[i] = 999999;
    }
    //First is the distance, second is the city
    priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> q;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> t;
        routes[A].push_back(make_pair(t,B));
        routes[B].push_back(make_pair(t,A));
    }
    
    q.push(make_pair(0,0));
    arr[0] = 0;
    
    while (!q.empty()) {
        pair<int,int> x = q.top();
        for (int i = 0; i < routes[x.second].size(); i++) {
            auto aa = routes[x.second][i];
            if (arr[aa.second] > aa.first + x.first) {
                arr[aa.second] = aa.first + x.first;
                //cout << arr[aa.second] << " " << aa.second << endl;
                q.push(make_pair(arr[aa.second],aa.second));
            }
        }
        q.pop();
    }
    priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> p;
    p.push(make_pair(0,N-1));
    ans[N-1] = 0;
    while (!p.empty()) {
        pair<int,int> x = p.top();
        for (int i = 0; i < routes[x.second].size(); i++) {
            auto aa = routes[x.second][i];
            if (ans[aa.second] > aa.first + x.first) {
                ans[aa.second] = aa.first + x.first;
                //cout << arr[aa.second] << " " << aa.second << endl;
                p.push(make_pair(ans[aa.second],aa.second));
            }
        }
        p.pop();
    }
    int mx = ans[0] + arr[0];
    for (int i = 1; i < N; i++) {
        mx = max(mx,ans[i]+arr[i]);
    }
    cout << mx << "\n";

    
}