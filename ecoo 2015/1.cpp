#include <bits/stdc++.h>
using namespace std;

int main() {
    int freq[10];
    for (int i = 0; i < 10; i++) {
        string s;
        int tot=0;
        memset(freq,0,sizeof(freq));
        while (true) {
            cin >> s;
            if (s == "end") {
                cin >> s;
                cin >> s;
                break;
            }
            //orange ones, then blue, green, yellow, pink, violet, brown and finally red.
            if (s == "orange") ++freq[0];
            else if (s == "blue") ++freq[1];
            else if (s == "green") ++freq[2];
            else if (s == "yellow") ++freq[3];
            else if (s == "pink") ++freq[4];
            else if (s == "violet") ++freq[5];
            else if (s == "brown") ++freq[6];
            else if (s == "red") tot += 16;
        }
        for (int j = 0; j <= 6; j++) {
            tot += (freq[j] / 7)*13;
            if (freq[j] % 7 != 0) tot+=13;
        }
        cout << tot << endl;

    }

}