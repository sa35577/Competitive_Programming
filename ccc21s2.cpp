#include <bits/stdc++.h>
using namespace std;


vector<int> R;
vector<int> C;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int M,N;
    cin >> M >> N;
    int Q;
    cin >> Q;
    R.resize(M+1);
    C.resize(N+1);
    char c;
    int val;
    while (Q--) {
        cin >> c >> val;
        if (c == 'R') {
            R[val]++;
        }
        else if (c == 'C') {
            C[val]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if ((R[i] + C[j]) % 2 == 1) {
                ans++;
            }
        }
    }
    cout << ans;
}