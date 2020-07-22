#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");

    int n;
    int val;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> val;
        ans = ans ^ val;
    }
    cout << ans << endl;
}