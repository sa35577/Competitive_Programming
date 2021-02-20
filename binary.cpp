#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x;
    long long arr[31];
    arr[0] = 1LL;
    for (int i = 1; i < 31; i++) arr[i] = 2*arr[i-1];
    int mx;
    while (n--) {
        cin >> x;
        if (x == 0) {
            cout << "0000\n";
        }
        else {
            mx = -1;
            bitset<32> b;
            for (int i = 30; i >= 0; i--) {
                if (x >= arr[i]) {
                    x -= arr[i];
                    b[i] = 1;
                    mx = max(mx,i);
                }
            }
            string sti = "";
            while (mx % 4 != 3) mx++;
            int cnt = 0;
            for (int i = mx; i >= 0; i--) {
                cnt++;
                sti += (b[i] ? '1' : '0');
                if (cnt == 4) cnt = 0, sti += ' ';
            }
            sti.pop_back();
            cout << sti << "\n";
            
        }
    }
}