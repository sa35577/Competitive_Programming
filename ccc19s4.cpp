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
//#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/
int N,K,p;
const int MAXN = 1000005, MAXLOG = 23;
int LOG[MAXN];
ll st[MAXN][MAXLOG];
ll arr[MAXN],day[MAXN],dp[MAXN];



void buildTable() {
    LOG[1] = 0;
    rep(i,2,N+2,1) {
        LOG[i] = LOG[i >> 1] + 1;
    }
    rep(i,1,N+1,1) {
        st[i][0] = arr[i];
    }
    rep(j,1,MAXLOG,1) {
        for (int i = 0; i + (1 << j) <= N; i++) {
            st[i][j] = max(st[i][j-1],st[i+(1 << (j-1))][j-1]);
        }
    }
}

ll rmq(int L, int R) {
    int j = LOG[R-L+1];
    return max(st[L][j],st[R-(1 << j) + 1][j]);
}

deque<pair<int,ll>> d1;
deque<int> d2;

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> N >> K;
    rep(i,1,N+1,1) {
        cin >> arr[i];
        day[i] = (i + K - 1)/K;
    }
    buildTable();
    int curDay = 0, curMax = 0;
    rep(i,1,N+1,1) {
        if (day[i] > curDay) {
            rep(j,max(0,i-K),i,1) {
                ll qVal = dp[j] + rmq(j+1,i);
                while (!d1.empty() && qVal > d1.back().s) d1.pop_back();
                while (!d2.empty() && dp[j] > dp[d2.back()]) d2.pop_back();
                d1.push_back({j,qVal});
                d2.push_back(j);
            }
            curDay++;
            curMax = 0;
        }
        curMax = max(curMax,int(arr[i]));
        while (d1.front().f < i-K) d1.pop_front();
        while (d2.front()   < i-K) d2.pop_front();
        dp[i] = max(d1.front().s,dp[d2.front()]+curMax);
        
    }
    cout << dp[N] << endl;
    
   



}