#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ll n,a,b,t;
    for (int zz = 0; zz < N; zz++) {
        cin >> n >> a >> b >> t;
        if (n * a < t) cout << -1 << "\n";
        else {
            cout << n-(n*a -t)/(a+b) << "\n"; 
        }
    }
}