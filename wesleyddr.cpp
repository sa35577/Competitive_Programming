#include <bits/stdc++.h>
using namespace std;

struct value {
    string str;
    int val;
} arr[5];

int main() {
    string s;
    cin >> s;
    int combos;
    cin >> combos;
    int score = s.size();
    for (int i = 0; i < combos; i++) {
        cin >> arr[i].str >> arr[i].val;
    }
    int cur = 0,mxstr=0,add=0;
    while (cur < s.size()) {
        mxstr = 0; add = 0;
        for (int i = 0; i < combos; i++) {
            if (s.substr(cur).find(arr[i].str) == 0 && mxstr < arr[i].str.size()) {
                mxstr = arr[i].str.size()-1;
                add = arr[i].val;
            }
        }
        cur = cur + mxstr+1;
        score += add;
        
    }
    cout << score;

}