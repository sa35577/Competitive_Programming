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


/*---END OF TEMPLATE---*/

ll fastPow(ll base, ll power) {
    ll result = 1;
    while(power > 0) {
        if(power & 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}


ll nCR(ll n, ll r) {
    ll R = 0;
    ll cur = 1;
    while (R < r) {
        cur = (cur * (n-R))%MOD;
        cur = (cur * fastPow(R+1,MOD-2)) % MOD;
        R++;
    }
    return cur;
}

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    ll w,h;
    cin >> w >> h;
    ll n = w+h-2,r = 0,cur = 1;
    ll noObstacles = nCR(w+h-2,h-1);
    //cout << cur << endl;
    int x;
    cin >> x;
    ll x1,y1,x2,y2;
    if (x == 0) {
        while (noObstacles < 0) {
            noObstacles += MOD;
        }
        noObstacles %= MOD;
        cout << noObstacles << endl;
        return 0;
    }
    else if (x == 1) {
        cin >> x1 >> y1;
        ll n1 = x1 + y1 - 2, r1 = x1 - 1;
        ll n2 = w+h - x1-y1, r2 = h - y1;
        ll cur = ((noObstacles) - nCR(n1,r1)*nCR(n2,r2) + MOD) % MOD;
        while (cur < 0) {
            cur = cur + MOD;
        }   
        cur = cur % MOD;
        cout << cur << endl;
        return 0;
    }
    else if (x == 2) {
        cin >> x1 >> y1 >> x2 >> y2;
        bool r12 = false, r21 = false;
        if (x1 <= x2 && y1 <= y2) r12 = true;
        if (x2 <= x1 && y2 <= y1) r21 = true;
        ll cur = ((noObstacles) - nCR(x1 + y1 - 2,x1-1)*nCR(w+h - x1 - y1,h-y1) + MOD - nCR(x2 + y2 - 2,x2-1)*nCR(w+h - x2 - y2,h-y2) + MOD) % MOD;
        if (r12) {
            cur = cur + (((nCR(x1 + y1 - 2,x1-1)*nCR(x2+y2-x1-y1,y2-y1))% MOD)*nCR(w+h - x2 - y2,h-y2)) % MOD;
            cur = cur % MOD;
        }
        if (r21) {
            cur = cur + (((nCR(x2 + y2 - 2,x2-1)*nCR(x1+y1-x2-y2,y1-y2)) % MOD)*nCR(w+h - x1 - y1,h-y1)) % MOD;
            cur = cur % MOD;
        }
        while (cur < 0) {
            cur = cur + MOD;
        }   
        cur = cur % MOD;

        cout << cur << endl;

    }


}