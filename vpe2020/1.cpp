#include <bits/stdc++.h>
using namespace std;

int arr[5],lst[5];
int main() {
    int mx=INT_MAX,my=INT_MAX;
    for (int i = 0; i < 5; i++)  cin >> arr[i];
    for (int i = 0; i < 5; i++) cin >> lst[i];
    int a = 0, b = 0;
    for (int i = 0; i < 5; i++) {
        a += arr[i];
        mx = min(mx,arr[i]);
        b -= arr[i];
        my = min(my,lst[i]);
    }
    cout << max(a-mx,b-my);
    
}