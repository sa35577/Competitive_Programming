#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
ll arr[200000];
ll brr[200000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    cin >> arr[0];
    brr[0] = 0;
    for (ll i = 1; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (ll i = 1; i < n; i++) {
        brr[i] = arr[i] - arr[i-1];
    }
    ll prev = 0,tot = 0,largest = 0,c = 0;
    while (prev < n) {
        tot = 0;c = 1;
        for (ll i = prev+1; i < n; i++) {
            if (tot + brr[i] > k) {
                largest = max(largest,c);
                break;
            }
            else {
                c++;
                tot += brr[i];
            } 
        }
        prev++;
    }
    cout << largest << endl;
}