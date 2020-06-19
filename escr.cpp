#include <bits/stdc++.h>
using namespace std;

int main() {
    long long d;
    long long h;
    cin >> d;
    for (long long i = 0; i < d; i++) {
        cin >> h;
        long long x = h/3;
        if (h % 3 == 0) cout << x*x*x << endl;
        else if (h % 3 == 1) cout << x*x*(x+1) << endl;
        else cout << x*(x+1)*(x+1) << endl;
    }
}