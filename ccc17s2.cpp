#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int R = (n-1)/2,L = R+1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << v[R--] << " ";
        }
        else {
            cout << v[L++] << " ";
        }
    }
}