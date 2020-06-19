#include <bits/stdc++.h>
using namespace std;

int main() {
    int scale;
    cin >> scale;
    string str1 = "";
    for (int i = 0; i < scale; i++) {
        str1 += "*";
    }
    for (int i = 0; i < scale; i++) {
        str1 += "x";
    }
    for (int i = 0; i < scale; i++) {
        str1 += "*";
    }
    for (int i = 0; i < scale; i++) {
        cout << str1 << endl;
    }
    str1 = "";
    for (int i = 0; i < scale; i++) {
        str1 += " ";
    }
    for (int i = 0; i < scale; i++) {
        str1 += "x";
    }
    for (int i = 0; i < scale; i++) {
        str1 += "x";
    }
    for (int i = 0; i < scale; i++) {
        cout << str1 << endl;
    }
    str1 = "";
    for (int i = 0; i < scale; i++) {
        str1 += "*";
    }
    for (int i = 0; i < scale; i++) {
        str1 += " ";
    }
    for (int i = 0; i < scale; i++) {
        str1 += "*";
    }
    for (int i = 0; i < scale; i++) {
        cout << str1 << endl;
    }

}
