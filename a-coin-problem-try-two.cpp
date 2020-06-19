#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
ll n,v;
ll dp[10005], ndp[10005], coins[10005];
ll c,l;
vector<pair<ll,ll>> computed[10005];
//     pair<c,ans>              l

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin >> n >> v;
    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }
    bool done;
    for (ll kk = 0; kk < v; kk++) {
        cin >> c >> l;
        done = false;
        for (ll i = 0; i < computed[l].size(); i++) {
            if (computed[l][i].first == c) {
                cout << computed[l][i].second << endl;
                done = true;
                break;
            }
        }
        if (done) continue;
        for (ll i = 0; i < 10005; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for (ll i= 0; i < l; i++) {
            for (ll i = 0; i < 10005; i++) ndp[i] = INT_MAX;
            for (ll j = 0; j <= c; j++) {
                ndp[j] = dp[j];
                if (j - coins[i] >= 0) {
                    ndp[j] = min(dp[j],ndp[j-coins[i]]+1);
                }
                
            }
            for (ll j = 0; j < 10005; j++) dp[j] = ndp[j];
        }
        if (ndp[c] >= INT_MAX) {
            cout << -1 << endl;
            computed[l].push_back({c,-1});
        }
        else {
            cout << ndp[c] << endl;
            computed[l].push_back({c,ndp[c]});
        }
    }
}