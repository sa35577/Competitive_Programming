#include <bits/stdc++.h>
using namespace std;

int evt[1005];
int main() {
    for (int zz = 0; zz < 10; zz++) {
        int n,m,d,evDay,tot=0;
        cin >> n >> m >> d;
        int cur = n;
        fill(evt,evt+1005,false);
        for (int i = 0; i < m; i++) {
            cin >> evDay;
            evt[evDay]++;
        }
        for (int i = 1; i <= d; i++) {
            if (cur == 0) {
                cur = n;
                ++tot;
            }
            cur -= 1;
            if (evt[i] > 0) {
                cur += evt[i];
                n += evt[i];
            }
        }
        cout << tot << endl;



    }
}