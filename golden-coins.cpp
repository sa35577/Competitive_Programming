#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define for(i,j,k,in) for (int i = j; i < k; i += in)

/*---END OF TEMPLATE---*/




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int x;
    cin >> x;
    int tot = 0;
    tot += 1000* (x/500);
    x = x % 500;
    tot += 5 * (x/5);
    cout << tot;
}