#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

unordered_map<int,int> mp;



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int ln1,ln2;
    scan(ln1);
    int a1[ln1];
    rep(i,0,ln1,1) {
        scan(a1[i]);
        mp[a1[i]] = i;
    }
    scan(ln2);
    int val;
    vi indices;
    rep(i,0,ln2,1) {
        scan(val);
        if (mp.find(val) != mp.end()) {
            indices.push_back(mp[val]);
        }
    }

    //LIS
    int I[indices.size()];
    int mx = 0, inf = MOD;
    I[0] = -inf;
    for (int i = 1; i <= indices.size(); i++) {
        I[i] = inf;
    }
    for (int i = 0; i < indices.size(); i++) {
        int low,high,m;
        low = 0;
        high = mx;
        while (low <= high) {
            m = (low+high)/2;
            if (I[m] < indices[i]) {
                low = m+1;
            }
            else {
                high = m - 1;
            }
            
        }
        I[low] = indices[i];
        if (mx < low) mx = low;
    }
    cout << mx << endl;



}