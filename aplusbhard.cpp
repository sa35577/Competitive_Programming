#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    string os;
    if (a.length() < b.length()) {
        for (int i = 0; i < b.length() - a.length(); i++)
            os.append("0");
        os.append(a);
        int carry = 0;
        int x;
        string ans;
        for (long long i = os.size(); i >= 0; i--) {
            x = stoi(b[i])+stoi(os[i])+carry;
            if (x > 10) {
                x -= 10;
                carry = 1;
            }
            else
                carry = 0;
            ans[i] = to_string(x);
        }
        cout << ans;
    }
    else if (a.length() > b.length()) {
        for (int i = 0; i < a.length() - b.length(); i++)
            os.append("0");
        os.append(b);
    }


    cout << os << endl;
    cout << b << endl;
}
