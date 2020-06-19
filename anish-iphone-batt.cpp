#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int E,N;
    cin >> E >> N;
    string names[N+1];
    int costs[N+1];
    int weights[N+1];
    int dp[N+1][E+1];
    vector <string> v;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= E; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> names[i] >> weights[i] >> costs[i];
        if (costs[i] == 0 && weights[i] == 0) v.push_back(names[i]);
        for (int j = 0; j <= E; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= costs[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-costs[i]] + weights[i]);
        }
    }
    int se = E, sn = N;
    
    
    while (true) {
        if (dp[sn][se] == dp[sn][se-1]) se = se-1;
        else break;
    }
    cout << dp[sn][se] << " " << se << "\n";

    while (sn > 0) {
        if (dp[sn-1][se] != dp[sn][se]) {
            se -= costs[sn];
            v.push_back(names[sn]);
        }
        sn--;
    }
    sort(v.begin(),v.end());
    string out = "";
    for (string s : v) out += s + " ";
    out.pop_back();
    cout << out;

    /*
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= E; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
}