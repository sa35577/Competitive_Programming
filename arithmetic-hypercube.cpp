#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size()-1];
}