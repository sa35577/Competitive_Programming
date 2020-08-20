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
#define ld long double
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
//const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int N,Q;
const int MAXN = 262144;
const int sz = 512;
const ll MOD = (ll)MAXN;
int nums[sz][sz];
unordered_map<int,int> freq[sz];
unordered_map<int,int> pre[sz][sz];
unordered_map<int,int>::iterator it;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N); scan(Q);
    int val;
    rep(i,0,N,1) {
        scan(val);
        nums[i/sz][i%sz] = val;
        if (freq[i/sz].find(val) == freq[i/sz].end()) freq[i/sz][val] = 1;
        else freq[i/sz][val]++;
    }
    rep(i,0,sz,1) {
        unordered_map<int,int> mp = freq[i];
        pre[i][i] = mp;
        rep(j,i+1,sz,1) {
            for (it = freq[j].begin(); it != freq[j].end(); it++) {
                if (mp.find(it->first) == mp.end()) mp[it->first] = it->second;
                else mp[it->first] += it->second;
            }
            pre[i][j] = mp;
        }
    }

    int x,y;
    ll ans = 0;
    rep(bob,0,Q,1) {
        scan(x); scan(y);
        x = x ^ (int)ans;
        y = y ^ (int)ans;
        ans = 0;
        int xdiv = x/sz, xmod = x%sz, ydiv = y/sz, ymod = y%sz;
        unordered_map<int,int> mp;
        if (xdiv == ydiv) {
            rep(i,xmod,ymod+1,1) {
                if (mp.find(nums[xdiv][i]) == mp.end()) mp[nums[xdiv][i]] = 1;
                else mp[nums[xdiv][i]]++;
            }
        }
        else {
            rep(i,xmod,sz,1) {
                if (mp.find(nums[xdiv][i]) == mp.end()) mp[nums[xdiv][i]] = 1;
                else mp[nums[xdiv][i]]++;
            }
            for (it = pre[xdiv+1][ydiv-1].begin(); it != pre[xdiv+1][ydiv-1].end(); it++) {
                if (mp.find(it->first) == mp.end()) mp[it->first] = it->second;
                else mp[it->first] += it->second;
            }
            /*rep(i,xdiv+1,ydiv,1) {
                for (it = freq[i].begin(); it != freq[i].end(); it++) {
                    if (mp.find(it->first) == mp.end()) mp[it->first] = it->second;
                    else mp[it->first] += it->second;
                }
            }*/
            rep(i,0,ymod+1,1) {
                if (mp.find(nums[ydiv][i]) == mp.end()) mp[nums[ydiv][i]] = 1;
                else mp[nums[ydiv][i]]++;
            }
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            ans += (it->second * it->second) % MOD;
            ans %= MOD;
        }
        printf("%lld\n",ans);
    }

}