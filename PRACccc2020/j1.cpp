#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 || n > 8) cout << 1;
    else if (n < 4 || n > 6) cout << 2;
    else cout << 3;
}