#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long I,N,J,XI,XF,K;
    cin >> I >> N >> J;
    long long arr[I+2];
    for (long long i = 0; i < I+2; i++) {
        arr[i] = 0;
    }
    for (long long a = 0; a < J; a++) {
        cin >> XI >> XF >> K;
        arr[XI] += K;
        arr[XF+1] -= K;
    }
    long long count = 0,x = 0;
    for (long long i = 1; i < I+1; i++) {
        x += arr[i];
        if (x < N) {
            count++;
        }

    }
    cout << count;
}