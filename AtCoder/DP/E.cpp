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
    int N;
    ll W;
    cin >> N >> W;
    ll dp[100001];
    dp[0] = 0;
    for (int i = 1; i < 100001; i++) {
        dp[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        ll w;
        int v;
        cin >> w >> v;
        for (int j = 100000 - v; j >= 0; j--) {
            if (dp[j] != -1 && dp[j]+w <= W) {
                if (dp[j+v] == -1 || dp[j+v] > dp[j]+w) {
                    dp[j+v] = dp[j]+w;
                }
            }
        }
    }
    int mx = 0;
    for (int i = 100000; i >= 0; i--) {
        if (dp[i] != -1) {
            mx = i;
            break;
        }
    }
    cout << mx << endl;
    



}