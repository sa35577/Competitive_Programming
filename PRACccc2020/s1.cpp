#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int lst[1005];
    int arr[1005];
    int cnt = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> lst[i];
    int c = 0;
    while (c < n) {
        if (arr[c] == lst[c]) {
            ++cnt;
            while (arr[c] == lst[c]) {
                ++c;
                if (c >= n) break;
            }
        }
        ++c;
    }
    cout << cnt;
}