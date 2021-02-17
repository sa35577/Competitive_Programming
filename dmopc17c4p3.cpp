#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

const int MAXN = 100005;
priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>> pq;
ll mxDist[MAXN];
vector<pair<ll,int>> graph[MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int a,b;
    ll c;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }

    pq.push({0LL,{1,-1}});
    while (!pq.empty()) {
        ll dist = pq.top().f;
        int node = pq.top().s.f,prev = pq.top().s.s;
        pq.pop();
        if (dist >= mxDist[node]) {
            for (pair<ll,int> nxt : graph[node]) {
                if (nxt.s != prev) {
                    if (dist + nxt.f > mxDist[nxt.s]) {
                        mxDist[nxt.s] = dist + nxt.f;
                        pq.push({mxDist[nxt.s],{nxt.s,node}});
                    }
                }
            }
        }
    }

    int startNode = -1;
    ll mx = -1, mx2 = -1;
    for (int i = 1; i <= N; i++) {
        if (mxDist[i] > mx) {
            startNode = i;
            mx = mxDist[i];
        }
    }
    memset(mxDist,0,sizeof(mxDist));

    pq.push({0LL,{startNode,-1}});
    while (!pq.empty()) {
        ll dist = pq.top().f;
        int node = pq.top().s.f,prev = pq.top().s.s;
        pq.pop();
        if (dist >= mxDist[node]) {
            for (pair<ll,int> nxt : graph[node]) {
                if (nxt.s != prev) {
                    if (dist + nxt.f > mxDist[nxt.s]) {
                        mxDist[nxt.s] = dist + nxt.f;
                        pq.push({mxDist[nxt.s],{nxt.s,node}});
                    }
                }
            }
        }
    }

    mx = -1;
    int pNode = startNode;

    for (int i = 1; i <= N; i++) {
        if (mxDist[i] >= mx) {
            startNode = i;
            mx2 = mx;
            mx = mxDist[i];
        }
        else if (mxDist[i] > mx2) mx2 = mxDist[i];
    }
    memset(mxDist,0,sizeof(mxDist));

    pq.push({0LL,{startNode,-1}});
    while (!pq.empty()) {
        ll dist = pq.top().f;
        int node = pq.top().s.f,prev = pq.top().s.s;
        pq.pop();
        if (dist >= mxDist[node]) {
            for (pair<ll,int> nxt : graph[node]) {
                if (nxt.s != prev) {
                    if (dist + nxt.f > mxDist[nxt.s]) {
                        mxDist[nxt.s] = dist + nxt.f;
                        pq.push({mxDist[nxt.s],{nxt.s,node}});
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (mxDist[i] >= mx && i != pNode) {
            startNode = i;
            mx2 = mx;
            mx = mxDist[i];
        }
        else if (mxDist[i] > mx2 && i != pNode) mx2 = mxDist[i];
    }

    cout << mx2 << "\n";

}