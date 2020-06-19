#include <bits/stdc++.h>
using namespace std;
int a,b;
int divi(int factor, int occurences) {
    int t = 0;
    int dividend = b;
    while (dividend != 0) {
        t += dividend/factor;
        dividend = dividend/factor;
    }
    return t/occurences;
}

unordered_map<int,int> mp;
unordered_map<int,int>::iterator it;
int main() {
    
    cin >> a >> b;
    int dec = a;
    int cur = 2;
    while (dec != 1) {
        if (dec % cur == 0) {
            dec = dec/cur;
            if (mp.find(cur) == mp.end()) {
                mp[cur] = 1;
            }
            else mp[cur]++;
        }
        else {
            if (cur == 2) cur++;
            else cur += 2;
        }
    }
    int mx = 1000000000;
    for (it = mp.begin(); it != mp.end(); it++) {
        int c = it->first, d = it->second,e=divi(c,d);
        if (mx > e) mx = e;
    }
    cout << mx;



}