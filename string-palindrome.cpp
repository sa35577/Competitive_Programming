#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define for(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    string s,k;
    cin >> s;
    k = s;
    reverse(k.begin(),k.end());
    bool flag = false;
    if (s != k) flag = true;
    string t="",u;
    for (i,0,(s.size()-1)/2,1) {
        t += s[i];
    }
    u = t;
    reverse(u.begin(),u.end());
    if (t != u) flag = true;
    string v = "",w;
    for (i,(s.size()+3)/2-1,s.size(),1) {
        v += s[i];
    }
    w = v;
    reverse(v.begin(),v.end());
    if (v != w) flag = true;
    if (flag) cout << "No";
    else cout << "Yes";


}