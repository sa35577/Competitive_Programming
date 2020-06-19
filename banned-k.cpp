#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/
int n;
ll freq[2000005];
ll arr[2000005];

unordered_map<ll,ll>mp;
ll nC2(ll n) {
    if (n == 0) {
        mp[0] = 0;
        return 0;
    }
    if (mp.find(n) != mp.end()) return mp[n];
    mp[n] = (n*(n-1))/2;
    return mp[n];
}

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> n;
    rep(i,0,2000005,1) freq[i] = 0;
    rep(i,0,n,1) {
        cin >> arr[i];
        arr[i]--;
        freq[arr[i]]++;
    }
    ll tot = 0;
    rep(i,0,n,1) {
        tot += nC2(freq[i]);
    }
    rep(i,0,n,1) {
        ll x = tot;
        x -= freq[arr[i]]-1;
        cout << fixed << x << "\n";
    }
    

}