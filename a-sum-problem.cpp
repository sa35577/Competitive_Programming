#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

vll bSearch(ll left, ll right, ll exploited, ll cur) {
    vll v;
    if (left == right || cur == 0) {
        for (ll i = 0; i < cur; i++) {
            v.push_back(left);
        }
        return v;
    }
    ll query = (left+right)/2,valRight;
    cout << "? " << query;
    cin >> valRight;



}



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");

}