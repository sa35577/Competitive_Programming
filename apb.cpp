#include <bits/stdc++.h>
using namespace std;

void add(string n1, string n2) {
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
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
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
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }

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
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
    }
    ans.clear();
    cout << endl;
}

void subtract(string n1, string n2) {
    vector<int> ans;
    if (n1.size() > n2.size()) {
        //cout << "A" << endl;
        string os;
        for (int i = 0; i < n1.size()-n2.size(); i++) {
            os.push_back('0');
        }
        for (int i = 0; i < n2.size(); i++) {
            os.push_back(n2[i]);
        }
        int dig;
        int carry = 0;
        for (int i = n1.size() - 1; i >= 0; i--) {
            dig = int(n1[i]) - int(os[i]) - carry;
            if (dig < 0) {
                carry = 1;
                dig += 10;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(dig);
            //cout << dig << endl;
        }
        reverse(ans.begin(),ans.end());
        if (ans[0] == 0) {
            ans.erase(ans.begin());
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
           
    }

    else if (n1.size() < n2.size()) {
        //cout << "B" << endl;
        string os;
        for (int i = 0; i < n2.size()-n1.size(); i++) {
            os.push_back('0');
        }
        for (int i = 0; i < n1.size(); i++) {
            os.push_back(n1[i]);
        }
        int dig;
        int carry = 0;
        for (int i = n2.size() - 1; i >= 0; i--) {
            dig = int(n2[i]) - int(os[i]) - carry;
            if (dig < 0) {
                carry = 1;
                dig += 10;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(dig);
        }
        reverse(ans.begin(),ans.end());
        if (ans[0] == 0) {
        ans.erase(ans.begin());
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
    
    }
    else {
        //cout << "C" << endl;
        int dig;
        int carry = 0;
        for (int i = n1.size() - 1; i >= 0; i--) {
            dig = int(n1[i]) - int(n2[i]) - carry;
            if (dig < 0) {
                carry = 1;
                dig += 10;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(dig);
        }
        reverse(ans.begin(),ans.end());
        if (ans[0] == 0) {
            ans.erase(ans.begin());
        }        
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
    }
    cout << endl;
    ans.clear();

}
int main() 
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int tries;
    cin >> tries;
    string n1,n2;
    for (int linuxsucks = 0; linuxsucks < tries; linuxsucks++)
    {
        cin >> n1 >> n2;
        bool wtf = true;
        if (n1[0] != '-' && n2[0] != '-')
            add(n1,n2);
        else if (n1[0] != '-' && n2[0] == '-') {
            n2.erase(n2.begin());
            if (n1.size() > n2.size()) {
                subtract(n1,n2);
            }
            else if (n1.size() < n2.size()) {
                if (wtf) {
                    cout << "-";
                    wtf = false;
                }
                subtract(n2,n1);

            }
            else {
                auto done = false;
                auto ind = 0;
                while (not done) {
                    if (int(n1[ind]) != int(n2[ind])) {
                        done = true;
                        if (int(n1[ind]) > int(n2[ind])) {
                            subtract(n1,n2);
                        }
                        else {
                            if (wtf) {
                                cout << "-";
                                wtf = false;
                            } 
                            subtract(n2,n1);
                        }
                    }
                    else if (ind == n1.size()) {
                        cout << 0 << endl;
                        done = true;
                    }
                    else {
                        ind ++;
                    }
                }
            }
        }
        else if (n2[0] != '-' && n1[0] == '-') {
            n1.erase(n1.begin());
            if (n2.size() > n1.size()) {
                subtract(n2,n1);
            }
            else if (n2.size() < n1.size()) {
                if (wtf) {
                    cout << "-";
                    wtf = false;
                }
                
                subtract(n1,n2);

            }
            else {
                auto done = false;
                auto ind = 0;
                while (not done) {
                    if (int(n2[ind]) != int(n1[ind])) {
                        done = true;
                        if (int(n2[ind]) > int(n1[ind])) {
                            subtract(n2,n1);
                        }
                        else {
                            if (wtf) {
                                cout << "-";
                                wtf = false;
                            }
                            subtract(n1,n2);
                        }
                    }
                    else if (ind == n1.size()) {
                        cout << 0 << endl;
                        done = true;
                    }
                    else {
                        ind ++;
                    }
                }
            }
        }
        else {
            if (wtf) {
                cout << "-";
                wtf = false;
            }
            n1.erase(n1.begin());
            n2.erase(n2.begin());
            add(n1,n2);
        }
    }
}