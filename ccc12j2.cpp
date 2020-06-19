#include <bits/stdc++.h>
using namespace std;

int main() {
    short w,x,y,z;
    cin >> w;
    cin >> x;
    cin >> y;
    cin >> z;
    if (z > y && y > x && x > w)
        cout << "Fish Rising";
    else if (z < y && y < x && x < w)
        cout << "Fish Diving";
    else if (z == y && y == x && x == w)
        cout << "Fish At Constant Depth";
    else
        cout << "No Fish";
    return 0;
}
