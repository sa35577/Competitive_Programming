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

const int MXSIZE = 3005;
double dp[MXSIZE][MXSIZE];
bool visited[MXSIZE][MXSIZE];
double prob[MXSIZE];

double solve (int idx, int heads) {
    if (heads < 0) return (double)0;
    if (idx == 0) {
        return heads == 0;
    }
    if (visited[idx][heads]) return dp[idx][heads];
    visited[idx][heads] = 1;

    return dp[idx][heads] = solve(idx-1,heads-1)*prob[idx] + ((double)1 - prob[idx])*solve(idx-1,heads);


}


int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n;
    cin >> n;
    double tot = 0;
    rep(i,1,n+1,1) {
        cin >> prob[i];
    }
    rep(i,0,n+1,1) {
        if (i > n- i) {
            tot += solve(n,i);
        }
    }
    printf("%.9f",tot);


}