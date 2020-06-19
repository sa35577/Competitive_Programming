#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[15];
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tot += arr[i];
    }
    tot /= n;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (tot != arr[i]) ++t;
    }
    cout << t;
}
