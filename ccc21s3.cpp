#include <bits/stdc++.h>
using namespace std;


#define ll long long

const int MAXN = 200005;
int P[MAXN],W[MAXN],D[MAXN];
vector<pair<int,int>> openLoop,closeLoop;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int openIdx = 0, closeIdx = 0, cur = 0;
    ll deltaLeft = 0, deltaRight = 0,ans = 0, sto = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> W[i] >> D[i];
        openLoop.push_back({P[i]-D[i],W[i]});
        closeLoop.push_back({P[i]+D[i],W[i]});
        deltaRight += W[i];
        ans += ((ll)W[i])*((ll)max(P[i]-D[i],0));
        //cout << ans << "\n";
    }
    sto = min(sto,ans);
    sort(openLoop.begin(),openLoop.end());
    sort(closeLoop.begin(),closeLoop.end());
    while (openIdx < N && openLoop[openIdx].first <= 0) deltaRight -= openLoop[openIdx].second, openIdx++;
    while (closeIdx < N && closeLoop[closeIdx].first <= 0) deltaLeft += closeLoop[closeIdx].second, closeIdx++;
    while (openIdx < N || closeIdx < N) {
        int nxt = INT_MAX;
        if (openIdx < N) nxt = min(nxt,openLoop[openIdx].first);
        if (closeIdx < N) nxt = min(nxt,closeLoop[closeIdx].first);
        ans += ((ll)(nxt-cur))*(deltaLeft-deltaRight);
        sto = min(sto,ans);
        //cout << nxt << " " << cur << " " << ans << "\n";
        cur = nxt;
        while (openIdx < N && openLoop[openIdx].first <= cur ) deltaRight -= openLoop[openIdx].second, openIdx++;
        while (closeIdx < N && closeLoop[closeIdx].first <= cur) deltaLeft += closeLoop[closeIdx].second, closeIdx++;
    }
    sto = min(sto,ans);
    cout << sto << "\n";

}