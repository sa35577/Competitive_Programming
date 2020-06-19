#include <bits/stdc++.h>

using namespace std;
int arr[1000000];

int main() {
    int a,x;
    for (int ii = 0; ii < 10; ii++) {
        cin >> a;
        x = 0;
        
        for (int i = 0; i < a; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < i; j++) {
                if (max(arr[i],arr[j]) % min(arr[i],arr[j]) == 0) {
                    x++;
                }
            }
        }
        cout << x << "\n";
    }
}