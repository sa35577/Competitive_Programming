#include <bits/stdc++.h>
using namespace std;

unsigned long long arr[10005];
int main() {
    unsigned long long k,n;
    unsigned long long tot = 0;
    bool flag = 0;
    cin >> k;
    for (unsigned long long aa = 0; aa < k; aa++) {
        cin >> n;
        
        tot = 0;
        for (unsigned long long bb = 0; bb < n; bb++) {
            cin >> arr[bb];
            tot+= arr[bb];
        }
        if (tot % n != 0) {
            cout << "Impossible" << "\n";       
        }
        else {
            tot = tot / n;
            flag = 0;
            for (unsigned long long kk = 0; kk < n; kk++) {
                if (arr[kk] == tot) {
                    flag = 1;
                    cout << kk+1 << "\n";
                    break;
                } 
            }
            if (!flag) {
                cout << "Impossible" << "\n";
            }
        }

    }
    return 0;
}