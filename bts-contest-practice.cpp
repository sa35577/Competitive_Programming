#include <bits/stdc++.h>
using namespace std;

int compare(int x[], int y[]) {
    int size = sizeof(x)/sizeof(x[0]);
    bool b1 = true,b2 = true;
    for (int i = 0; i < size; i++) {
        if (x[i] > y[i]) {
            b1 = false;
        }
        else if (x[i] < y[i]) {
            b2 = false;
        }
        if (!b1 & !b2) {
            return 0;
        }
    }
    if (b1 & b2) {
        return 0;
    }
    else if (b1 == 1) {
        return 1;
    }
    else {
        return 2;
    }
}

int main() {
    int p,q,n;
    cin >> p >> q >> n;
    int arr[n][p];
    int ans[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> arr[i][j];
            ans[i] = 1;
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x = compare(arr[i],arr[j]);
            if (x == 1) {
                ans[j]++;
            }
            else if (x == 2) {
                ans[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}