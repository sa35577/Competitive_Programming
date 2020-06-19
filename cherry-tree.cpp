#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,C,K;
ll cherries[10005ll],weights[10005ll];
vector<ll> tree[10005ll];

ll add(ll h) {
    for (ll i = 0; i < tree[h].size(); i++) {
        cherries[h] += add(tree[h][i]);
    }
    return cherries[h];
}

ll add2(ll h) {
    for (ll i = 0; i < tree[h].size(); i++) {
        weights[h] += add2(tree[h][i]);
    }
    return weights[h];
}

int main() {
    cin >> N >> C >> K;
    for (ll i = 0; i < N; i++) {
        cin >> cherries[i];
    }
    ll A,B,k;
    for (ll i = 0; i < N; i++) {
        weights[i] = 0;
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> A >> B >> k;
        A--;
        B--;
        tree[A].push_back(B);
        weights[B] += k;
    }
    add(0);
    add2(0);
    ll count = 0;
    for (ll i = 1; i < N; i++) {
        if (cherries[i] >= C && weights[i] <= K) {
            count++;
        }
    }
    cout << count << "\n";
 


}