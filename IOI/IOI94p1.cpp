//
// Created by satcl on 2020-05-04.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> lst;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> cur;
        int x;
        for (int j = 1; j <= i; j++) {
            cin >> x;
            cur.push_back(x);
        }
        lst.push_back(cur);
    }
    //cout << "hello";
    vector<vector<int>> lst2;
    for (int i = 1; i < n+1; i++) {
        vector<int> cur(i);
        fill(cur.begin(),cur.end(),0);
        lst2.push_back(cur);
    }
    //cout << "hello";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i + j == 0) {
                lst2[i][j] = lst[i][j];
            }
            else if (j == 0) {
                lst2[i][j] = lst[i][j] + lst2[i-1][j];
            }
            else if (j > 0 && j < i) {
                lst2[i][j] = lst[i][j]+max(lst2[i-1][j],lst2[i-1][j-1]);
            }
            else if (i == j)
                lst2[i][j] = lst[i][j] + lst2[i-1][j-1];
        }
    }
    //cout << "hello";
    int mx= INT_MIN;
    for (int i : lst2[n-1]) mx = max(mx,i);
    cout << mx << endl;


}
