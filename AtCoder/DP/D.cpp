//
// Created by satcl on 2020-05-05.
//
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


int n,w;
ll dp[1000000+2];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");

    scan(n); scan(w);

    memset(dp,0,sizeof(dp));
    rep(i,1,n+1,1) {
        int wei,val;
        scan(wei);
        scan(val);
        for (int j = w; j >= wei; j--) {
            dp[j] = max(dp[j-wei]+val,dp[j]);
        }
    }
    int mx = -1;
    rep(i,0,w+1,1) mx = max(dp[i],mx);
    cout << mx << endl;
}