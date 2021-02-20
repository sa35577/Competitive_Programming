#include <bits/stdc++.h>

using namespace std;

int main() {
    int freq[101];
    memset(freq,0,sizeof(freq));
    int n;
    while (1) {
        scanf("%d",&n);
        if (n == -1) break;
        ++freq[n];
    }
    vector<int> v;
    int mx = 0;
    for (int i = 0; i <= 100; i++) {
        if (freq[i] > mx) {
            v.clear();
            mx = freq[i];
        }
        if (freq[i] == mx) v.push_back(i);
    }
    for (int i : v) {
        printf("%d\n",i);
    }
}