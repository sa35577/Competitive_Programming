#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n;
    while (n--) {
        scanf("%lld",&x);
        if (x&(x-1)) printf("F\n");
        else printf("T\n");
    }
}