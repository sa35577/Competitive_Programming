#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "\"";
    string s = "";
    string t = "";
    while (t != "*") {
        getline(cin,t);
        s = s + t + "\n";

    }
    printf("%s",s);
    
}