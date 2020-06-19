#include <bits/stdc++.h>
using namespace std;

int freq[30] = {}, nfreq[30] = {};
struct let {
    string val;
    int freq[30] = {};
}mp[30];
int main() {
    for (int zz = 0; zz < 10; zz++) {
        int r,t;
        string a;
        cin >> r >> t >> a;
        char c,first = a[0],last = a[1];
        for (int i = 0; i < r; i++) {
            cin >> c >> mp[(int)c - 65].val;
            

        }
    }
}