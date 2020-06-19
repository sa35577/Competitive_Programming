#include <bits/stdc++.h>
using namespace std;
void vals(int ones, string curstr, int rem) {
    if (rem == 0 && ones == 0) cout << curstr << "\n";
    else if (rem >= ones) {
        if (ones >= 1) vals(ones-1,curstr+'1',rem-1);
        vals(ones,curstr+'0',rem-1);
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a,b;
    for (int kk = 0; kk < n; kk++) {
        cin >> a >> b;
        cout << "The bit patterns are\n";
        vals(b,"",a);
        if (kk != n-1) cout << "\n";
    }
}