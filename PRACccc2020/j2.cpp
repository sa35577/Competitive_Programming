#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100005;
    int n,t1=0,t2=0,cmp=0;
    cin >> n;
    int arr[N],lst[N];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    for (int i = 0; i < n; i++) {
        t1 += lst[i];
        t2 += arr[i];
        if (t1 == t2) cmp = i+1;
    }
    cout << cmp;
    return 0;
}