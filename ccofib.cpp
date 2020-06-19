#include <bits/stdc++.h>
using namespace std;

string add(string n1, string n2) {
    vector<int> ans;
    if (n1.size() > n2.size()) {
        string os;
        for (int i = 0; i < n1.size()-n2.size(); i++) {
            os.push_back('0');
        }
        for (int i = 0; i < n2.size(); i++) {
            os.push_back(n2[i]);
        }
        int carry = 0;
        int dig;
        for (int i = n1.size() - 1; i >= 0; i--) {
            dig = int(n1[i]) - 48 + int(os[i]) - 48 + carry;
            if (dig > 9)
            {
                carry = 1;
                dig -= 10;
            } 
            else
            {
                carry = 0;
            }
            ans.push_back(dig);
        }
        
        if (carry == 1)
        {
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        
    }
    else if (n1.size() < n2.size()) {
        string os;
        for (int i = 0; i < n2.size() - n1.size(); i++) {
            os.push_back('0');
        }
        for (int i = 0; i < n1.size(); i++) {
            os.push_back(n1[i]);
        }
        int carry = 0;
        int dig;
        for (int i = n2.size() - 1; i >= 0; i--) {
            dig = int(n2[i]) - 48 + int(os[i]) - 48 + carry;
            if (dig > 9)
            {
                carry = 1;
                dig -= 10;
            } 
            else
            {
                carry = 0;
            }
            ans.push_back(dig);
        }
        
        if (carry == 1)
        {
            ans.push_back(1);
            
        }
        reverse(ans.begin(),ans.end());
        

    }
    else {
        int carry = 0;
        int dig;
        for (int i = n2.size() - 1; i >= 0; i--) {
            dig = int(n2[i]) - 48 + int(n1[i]) - 48 + carry;
            if (dig > 9)
            {
                carry = 1;
                dig -= 10;
            } 
            else
            {
                carry = 0;
            }
            ans.push_back(dig);
        }
        
        if (carry == 1)
        {
            ans.push_back(1);
            
        }
        reverse(ans.begin(),ans.end());
        
    }
    string s = "";
    for (int i = 0; i < ans.size(); i++) {
        s += to_string(ans[i]);
    }
    ans.clear();
    return s;
    
    
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string arr[200];
    arr[0] = "1";
    arr[1] = "1";
    for (int i = 2; i < 200; i++) {
        arr[i] = add(arr[i-1],arr[i-2]);
    }
    int x;
    while (true) {
        cin >> x;
        if (x == 0) return 0;
        x--;
        cout << arr[x] << endl;
    }
}