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

int arr[3000005];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    deque<int> mx,mn;
    int n,k,L = 1;
    ll res = 0;
    cin >> n >> k;
    
    rep(x,1,n+1,1) {
        cin >> arr[x];
        while (!mx.empty() && mx.back() < arr[x]) mx.pop_back();
        mx.push_back(arr[x]);
        while (!mn.empty() && mn.back() > arr[x]) mn.pop_back();
        mn.push_back(arr[x]);
        while (mx.front() - mn.front() > k) {
            if (mx.front() == arr[L]) mx.pop_front();
            if (mn.front() == arr[L]) mn.pop_front();
            L++;
        }   
        res += (ll)(x-L+1);
    }
    cout << res << endl;

}