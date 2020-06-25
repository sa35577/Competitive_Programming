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




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n;
    cin >> n;
    vector<int> indices(n);
    rep(i,0,n,1) {
        cin >> indices[i];
    }
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