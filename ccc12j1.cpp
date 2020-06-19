#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x;
    cin >> y;
    int diff;
    if (y - x <= 0)
        cout << "Congratulations, you are within the speed limit!";
    else {
        diff = y - x;
        if (diff <= 20)
            cout << "You are speeding and your fine is $" << 100 << ".";
        else if (diff <= 30)
            cout << "You are speeding and your fine is $" << 270 << ".";
        else
            cout << "You are speeding and your fine is $" << 500 << ".";
    }
}
