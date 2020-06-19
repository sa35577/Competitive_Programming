#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define f first
#define s second

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    ll T;
    cin >> N >> T;
    vector<pair<int,int>> graph[N];
    int r,w,t;
    for (int i = 0; i < T; i++) {
        cin >> r >> w >> t;
        r--;
        w--;
        graph[r].push_back({t,w}); //distance, city
        graph[w].push_back({t,r}); //distance, city
    }
    int K;
    cin >> K;
    int cities[K];
    int manu[K];
    for (int i = 0; i < K; i++) {
        cin >> cities[i] >> manu[i];
        cities[i]--;
    }
    int des;
    cin >> des;
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    q.push(make_pair(0,des)); //distance, city
    unsigned long long arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = 999999;
    }
    arr[des] = 0;
    while (!q.empty) {
        auto x = q.top;
        for (int i = 0; i < graph[x.s].size(); i++) {
            if (graph[x.s][i].f+x.f < arr[graph[x.s][i].s]) {
                arr[graph[x.s][i].s] = graph[x.s][i].f+x.f;
                q.push(make_pair(arr[graph[x.s][i].s],graph[x.s][i].s)
            }
        }
        q.pop();

    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}