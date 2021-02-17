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

int n,q;
ll k;
const int MAXN = 100005;
int arr[MAXN];
ll pre[MAXN];
vector<int> indices[2005];

bool inBound(int idx, int lo, int hi) {
    int L = 0, R = indices[idx].size()-1;
    int mid = (L+R)>>1;
    int prev = -1;
    while (prev != mid) {
        if (indices[idx][mid] >= lo && indices[idx][mid] <= hi) {
            return true;
        }
        else if (indices[idx][mid] >= lo) {
            R = mid;
        }
        else {
            L = mid;
        }
        prev = mid;
        mid = (L+R)>>1;
    }
    return false;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> n >> k >> q;
    rep(i,1,n+1,1) {
        cin >> arr[i];
        indices[arr[i]+1000].push_back(i);
        pre[i] = pre[i-1] + (ll)arr[i];
    }
    rep(i,0,2005,1) indices[i].push_back(MOD);

    int A,B,X,Y;

    rep(i,0,q,1) {
        cin >> A >> B >> X >> Y;
        if (pre[Y]-pre[X-1] > k && indices[A+1000][upper_bound(indices[A+1000].begin(),indices[A+1000].end(),X-1) - indices[A+1000].begin()] <= Y && indices[B+1000][upper_bound(indices[B+1000].begin(),indices[B+1000].end(),X-1) - indices[B+1000].begin()] <= Y) printf("Yes\n");
        else printf("No\n");
    }


}