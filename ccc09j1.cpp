#include <bits/stdc++.h>
using namespace std;

int main() {
    long long num = 9780921418;
    int a,b,c,total;
    cin >> a;
    cin >> b;
    cin >> c;
    num = (1000 * num) + (100 * a) + (10 * b) + c;
    bool odd = true;
    total = 0;
    while (num > 0) {
        if (odd) {
            total += num % 10;
            odd = false;
            num = num / 10;
        }
        else {

            total += 3 * (num % 10);
            odd = true;
            num = num / 10;
        }
    }
    cout << "The 1-3-sum is " << total;
}
