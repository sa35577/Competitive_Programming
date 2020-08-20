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
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int N,M,Q;
const int MAXN = 200005;
int arr[MAXN];
vector<int> freq[MAXN],worth;



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    scan(N); scan(M);
    rep(i,1,N+1,1) {
        scan(arr[i]);
        freq[arr[i]].push_back(i);
    }
    rep(i,1,N+1,1) {
        if (freq[i].size() >= 450) {
            worth.push_back(i);
        }
    }
    scan(Q);
    int L,R;
    rep(bob,0,Q,1) {
        scan(L); scan(R);
        if (R-L+1 >= 1350) {
            bool found = 0; int good = 0;
            rep(i,0,worth.size(),1) {
                int idx = worth[i];
                int cnt = upper_bound(freq[idx].begin(),freq[idx].end(),R)-lower_bound(freq[idx].begin(),freq[idx].end(),L);
                good += (3*cnt)/(R-L+1);
                if (good >= 2) {
                    found = 1;
                    break;
                }
            }
            if (found) printf("YES\n");
            else printf("NO\n");
        }
        else {
            unordered_map<int,int> mp;
            rep(i,L,R+1,1) {
                if (mp.find(arr[i]) == mp.end()) mp[arr[i]] = 1;
                else ++mp[arr[i]];
            }        
            int good = 0;
            for (unordered_map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) {
                good += (3*(it->second))/(R-L+1);
                if (good >= 2) break;
            }
            if (good >= 2) printf("YES\n");
            else printf("NO\n");


            mp.clear();
        }
    }
    

}