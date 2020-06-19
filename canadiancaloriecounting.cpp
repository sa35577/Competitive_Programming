#include <bits/stdc++.h>
using namespace std;

int main() {
    int burger[4] = {461,431,420,0};
    int side[4] = {100,57,70,0};
    int drink[4] = {130,160,118,0};
    int dessert[4] = {167,266,75,0};
    int a,b,c,d;
    int total = 0;
    cin >> a;
    a --;
    total += burger[a];
    cin >> b;
    b--;
    total += side[b];
    cin >> c;
    c--;
    total += drink[c];
    cin >> d;
    d--;
    total += dessert[d];
    cout << "Your total Calorie count is " << total << ".";



}
