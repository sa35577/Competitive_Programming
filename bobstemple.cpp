#include <bits/stdc++.h>
using namespace std;

int freq[1000001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int mx = -1;
    fill(freq,freq+1000001,-1);
    int n;
    cin >> n;
    for (int i = 0,x; i < n; i++) {
        cin >> x;
        mx = max(mx,x);
        freq[x]++;
    }
    
    cout << 1;
    for (int i = 2; i <= mx; i++) cout << " " << i;
    for (int i = mx; i >= 1; i--) {
        for (int j = 0; j < freq[i]; j++) cout << " " << i;
    }

    
}