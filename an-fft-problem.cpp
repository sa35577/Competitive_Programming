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
const ll MOD = 998244353;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define for(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

const int MAXN = 2005;
ll A[2005];
int N;

ll pref[MAXN][MAXN];





int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N;
    for(i,1,N+1,1) cin >> A[i];
    //memset(dp,0,sizeof(dp));
    memset(pref,0,sizeof(pref));
    for (i,0,MAXN,1) {
        if (i == 0) {
            for (j,0,MAXN,1) pref[i][j] = 1;
        }
        else memset(pref[i],0,sizeof(pref[i]));
    }
    for(idx,1,N+1,1) {
        for(i,idx,N+1,1) {
            pref[idx][i] = ((A[i]*pref[idx-1][i-1]) % MOD + pref[idx][i-1]) % MOD;
            while (pref[idx][i] < 0) pref[idx][i] = (pref[idx][i] + MOD) % MOD;
        }
        cout << pref[idx][N] % MOD << " ";
    }



}