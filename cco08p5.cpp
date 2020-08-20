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
#define pii pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    /*const int MAX1 = 50005, MAX2 = 20005;
    int n,sm = 0;
    scan(n);
    short int arr[50005];
    int idx = 0;
    int cnt;
    short int val;
    rep(i,0,n,1) {
        cin >> cnt >> val;
        rep(ind,idx,idx+cnt,1) arr[ind] = val;
        idx = idx+cnt;
    }
    short int dp[MAX1][MAX2];*/

    /*
    int n,sm = 0;
    cin >> n;
    int arr[101];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sm += arr[i];
    }
    int dp[105][sm+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= sm; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sm; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
        }
    }
    int mn = 50000;
    for (int a = sm/2; a >= 0; a--) {
        if (dp[n][a] == 1) {
            mn = sm-2*a; break;
        }
        
    }
    cout << mn;

    */
}