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
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/

int n;
int freq[200005],arr[200005];
vector<int> v;
unordered_set<int> us;

int main() {
    scan(n);
    rep(i,0,n,1) {
        scan(arr[i]);
        us.insert(arr[i]);
    }
    for (unordered_set<int>::iterator it = us.begin(); it != us.end(); it++) v.push_back(*it);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    int tot = n,sz;
    bool flag;
    for (int idx = 2; idx*idx <= n; idx++) {
        memset(freq,0,sizeof(freq));
        sz = idx*idx;
        rep(nxt,sz-1,n,1) {
            flag = 0;
            if (nxt == sz-1) {
                rep(i,0,sz,1) freq[arr[i]]++;
            }
            else {
                freq[arr[nxt-sz]]--; freq[arr[nxt]]++;
                //if (freq[arr[nxt-sz]] % idx != 0 || freq[arr[nxt]] % idx != 0) flag = 1;

            }
            if (!flag) {
                ++tot;
                for (int i : v) {
                    if (freq[i] % idx != 0) {
                        --tot;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n",tot);


    return 0;
}