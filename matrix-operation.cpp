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
int N;
int dp[1505][1505],arr[1505][1505];

int trav(pair<int,p> cur) {
    int y = cur.s.f, x = cur.s.s;
    //int tot = 0;
    int addOn = 0;
    if (dp[y][x] != -1) return dp[y][x];
    if (x > 0) {
        if (arr[y][x] < arr[y][x-1]) {
            addOn = max(addOn,1+trav({arr[y][x-1],{y,x-1}}));
        }
    }
    if (x < N-1) {
        if (arr[y][x] < arr[y][x+1]) {
            addOn = max(addOn,1+trav({arr[y][x+1],{y,x+1}}));
        }
    }
    if (y > 0) {
        if (arr[y][x] < arr[y-1][x]) {
            addOn = max(addOn,1+trav({arr[y-1][x],{y-1,x}}));
        }
    }
    if (y < N-1) {
        if (arr[y][x] < arr[y+1][x]) {
            addOn = max(addOn,1+trav({arr[y+1][x],{y+1,x}}));
        }
    }
    dp[y][x] = addOn;
    return dp[y][x];

}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N;
    memset(dp,-1,sizeof(dp));
    vector<pair<int,p>> v;
    rep(i,0,N,1) {
        rep(j,0,N,1) {
            int val;
            cin >> val;
            arr[i][j] = val;
            v.push_back({val,{i,j}});
        }
    }
    sort(v.begin(),v.end(),greater<pair<int,p>>());
    dp[v[0].s.f][v[0].s.s] = 0;
    int mx = 0;
    for (pair<int,p> ele : v) {
        mx = max(trav(ele),mx);
    }
    cout << mx << endl;

    


}