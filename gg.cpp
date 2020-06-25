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
    string s;
    cin >> s;
    int dp[s.size()+1];
    dp[0] = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') {
            cur++;
        }
        dp[i+1] = cur;
    }
    int q;
    int l,r;
    cin >> q;
    rep(i,0,q,1) {
        cin >> l >> r;
        cout << dp[r+1] - dp[l] << endl;

    }
}