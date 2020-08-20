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
ll t;
const int MAXN = 100005;
bitset<MAXN> a,b;
string dummy;



void step(int st) {
    int p1 = ((ll)1<<st) % n, p2 = (n-p1) % n;
    rep(i,0,n,1) {
        b[i] = a[(i+p1)%n]^a[(i+p2)%n];
    }
    a = b;
    b.reset();
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> n >> t >> dummy;
    rep(i,0,n,1) {  
        a[i] = (dummy[i] == '1');
    }
    for (int i = 55; i >= 0; i--) {
        if ((t>>i)&1) step(i);
    }
    rep(i,0,n,1) cout << a[i];
    cout << endl;



}