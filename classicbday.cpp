#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 365) {
        cout << 100;
        return 0;
    }
    double tot = 1;
    for (int i = 1; i <= n; i++) {
        tot *= (double)(365+1-i)/365;
    }
    double x = 100- tot * 100;
    1
    printf("%.2f",x);


}