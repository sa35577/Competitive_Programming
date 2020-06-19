#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string sti;
    cin >> sti;
    int ind = 0,k = 0,count = 0;
    if (sti.size() % 2 == 0) {
        while (ind < sti.size()/2) {
            while (k < sti.size() && sti[ind] == sti[k]) {
                k++;
            }
            if (k - ind >= sti.size()/2) {
                for (int i = sti.size()/2; i <= k-ind; i++) {
                    count += k- ind - i + 1;
                }
            }
            ind = k;  
        }
    }
    else {
        while (ind <= sti.size()) {
            while (k < sti.size() && sti[ind] == sti[k]) {
                k++;
            }
            if (k - ind >= sti.size()/2) {
                for (int i = sti.size()/2; i <= k-ind; i++) {
                    count += k- ind - i + 1;
                }
            }
            ind = k;  
        }
    }
    cout << count;


}