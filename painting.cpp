#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w,n;
    cin >> h >> w >> n;
    int mx = max(h,w);
    if (n % mx == 0) cout << n/mx << endl;
    else cout << (n+mx)/mx << endl;
}