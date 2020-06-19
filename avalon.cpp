#include <bits/stdc++.h>
using namespace std;

int main() {

    int g;
    cin >> g;
    long long e,p;
    double num = 1.0;
    for (int i = 0; i < g; i++) {
        cin >> e >> p;
        num = num * (p-e) / p;
    }
    cout << num << endl;
    return 0;
}
