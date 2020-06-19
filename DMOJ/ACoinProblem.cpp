//
// Created by satcl on 2020-05-06.
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
//#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/
int n,v;
int dp[500005], coins[2005];
int ndp[2000][500005];
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        ll hash1 = hash<T1>{}(p.first);
        ll hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<ll,ll>,ll,hash_pair> mp;
unordered_map<int,int> taken;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(n); scan(v);
    rep(i,0,n,1) {
        scan(coins[i]);
        if (taken.find(coins[i]) != taken.end()) {
            coins[i] = -1;
        }
        else taken[coins[i]] = 0;
    }
    rep(bob,0,v,1) {
        int c,l;
        scan(c); scan(l);
        if (mp.find({c,l}) != mp.end()) {
            cout << mp[{c,l}] << endl;
        }
        else {
            rep(dog, 0, c+1, 1) dp[dog] = MOD;
            dp[0] = 0;
            rep(i, 0, l, 1) {
                if (coins[i] != -1) {
                    rep(j, coins[i], c + 1, 1) {
                        if (dp[j - coins[i]] != MOD) {
                            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                        }
                    }
                }
            }
            if (dp[c] == MOD) { cout << -1 << endl; mp[{c,l}] = -1; }
            else { cout << dp[c] << endl; mp[{c,l}] = dp[c]; }
        }
    }


}