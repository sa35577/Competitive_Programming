#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    rep(bob,0,10,1) {
        int m,n;
        ll k;
        cin >> m >> n >> k;
        vi arr(n+1),lst(n+1);
        rep(i,0,n,1) {
            int bobo;
            cin >> bobo;
            arr[i] = bobo;
        }
        arr[n] = 0;
        lst[n] = 0;
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        rep(i,0,n,1) {

        }
        ll cur = 0; int mxInd = 0;
        ll ncur = 0;
        while (true) {
            rep(i,0,cur+1,1) {
                ncur += (ll)(ceil)((double)(arr[cur]-arr[mxInd+1])/m);
            }
            if (ncur >= k) break;
            rep(i,0,cur+1,1) {
                
            }
        }




    }

}