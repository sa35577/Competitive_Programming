#include <bits/stdc++.h>
using namespace std;

int N;
int arr[11];
bitset<10001> dp,ndp;


int main() {
    cin >> N;
    dp[0] = 1;
    int sum = 0;
    for (int j = 1,x; j <= N; j++) {
        cin >> x;
        sum += x;
        for (int i = 0; i <= 10000; i++) {
            ndp[i] = ndp[i] | dp[i];
            if (i >= x) {
                ndp[i] = ndp[i] | dp[i-x];
            }
        }
        dp = ndp;
    }
    for (int i = sum/2; i >= 0; i--) {
        if (dp[i]) {
            cout << sum - 2*i;
            return 0;
        }
    }

}
