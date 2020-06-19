#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int tc = 0; tc < 5; tc++) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool flag;
        int prime;
        int nums[n];
        for (int i = 100001; i < 500000; i += 2) {
            flag = false;
            for (int j = 0; j < n; j++) {
                if (arr[j] % i != 0) {
                    flag = true;
                    break;
                }
            }
            if (flag == false && isPrime(i)) {
                prime = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i]/prime;
        }
        string out = " ABCDEFGHIJKLMNOPQRSTUVWXYZ.,!?";
        for (int i = 0; i < n; i++) {
            cout << out[nums[i]/100] << out[nums[i] % 100];
        }
        cout << endl;
    }
}