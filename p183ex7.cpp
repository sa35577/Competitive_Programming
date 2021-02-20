#include <bits/stdc++.h>

using namespace std;


bool isPrime(int x) {
    if (x % 2 == 0) return false;
    for (int i = 3; i*i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        if (i == 1) printf("0\n");
        else if (i == 2) printf("1\n");
        else if (i == 3) printf("1\n");
        else {
            if (isPrime(i)) printf("1\n");
            else printf("0\n");
        }
    }
    
    return 0;
}