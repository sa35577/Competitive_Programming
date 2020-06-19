#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
    string n1 = "",n2 = "",ans = "";
    long long x = s1.size(), y = s2.size();
    if (x == y) {
        n1 = s1;
        n2 = s2;
    } 
    else if (x > y) {
        n1 = s1;
        for (long long i = 0; i < x-y; i++) {
            n2 += '0';
        }
        for (long long i = 0; i < y; i++) {
            n2 += s2[i];
        }
    } 
    else if (x < y) {
        n2 = s2;
        for (long long i = 0; i < y-x; i++) {
            n1 += '0';
        }
        for (long long i = 0; i < x; i++) {
            n1 += s1[i];
        }
    }
    for (long long i = 0; i < n1.size(); i++) {
        ans += '0';
    }
    int dig = 0, carry = 0;
    
    for (long long i = n1.size()-1; i >= 0; --i) {
        dig = int(n1[i]) + int(n2[i]) - 96 + carry;
        if (dig >= 10) {
            carry = 1;
            dig -= 10;
        }
        else {
            carry = 0;
        }
        ans[i] = dig + '0';
    }
    if (carry == 1) {
        ans = '1' + ans;
    }
    return ans; 

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;
    string inp;
    cin >> inp;
    string total = "0", cur = "0";
    
    
    for (long long i = 0; i < N; i++) {
        if (inp[i] == '-') {
            cur.pop_back();
        }
        else {
            cur += inp[i];  
        }
        total = add(cur,total);
        
    }
    cout << total << endl;
    return 0;
    
}