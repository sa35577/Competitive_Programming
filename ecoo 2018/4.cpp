#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;


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
unordered_map<ll,ll> Fib;
unordered_map<ll,pair<ll,ll>> x;
unordered_map<ll,pair<ll,ll>> y;  

ll llmin(ll a, ll b) {
    if (a > b) return b;
    return a;
}
ll llmax(ll a, ll b) {
    if (a < b) return b;
    return a;
}
ll fib(ll n) {
    if (Fib.find(n) != Fib.end()) return Fib[n];
    Fib[n] = fib(n-1) + fib(n-2);
    return Fib[n];
}

pair<ll,ll> getX(ll n) {
    if (x.find(n) != x.end()) return x[n];
    if (n % 2 == 0) {
        if (n % 4 == 0) {
            x[n] = {x[n-1].s,x[n-1].s+fib(n)};
            return x[n];
        }
        //not divisible by 4
        x[n] = {x[n-1].f-fib(n),x[n-1].f};
        return x[n];
    }
    else {
        x[n] = {llmin(x[n-1].f,x[n-2].f),llmax(x[n-1].s,x[n-2].s)};
        return x[n];    
    }
    return x[n];
}

pair<ll,ll> getY(ll n) {
    if (y.find(n) != y.end()) {
        return y[n];
    }
    if (n % 2 == 0) {
        y[n] = {llmin(y[n-1].f,y[n-2].f),llmax(y[n-1].s,y[n-2].s)};
        return y[n];    
    }
    else {
        if (n % 4 == 3) {
            y[n] = {y[n-1].s,y[n-1].s+fib(n)};
            return y[n];
        }
        else { //n % 4 == 1
            y[n] = {y[n-1].f-fib(n),y[n-1].f};
            return y[n];
        }
    }
    return y[n];
}



int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    Fib[1] = 1;
    Fib[2] = 1;
    y[1] = {-1,0};
    y[2] = {-1,0};
    x[1] = {0,1};
    ll cx,cy;
    rep(bob,0,10,1) {
        cin >> cx >> cy;
        ll cur = 1;
        while (true) {
            pair<ll,ll> gx = getX(cur), gy = getY(cur);
            ll x1 = gx.f, x2 = gx.s, y1 = gy.f,y2 = gy.s;
            if (cx >= x1 && cx <= x2 && cy >= y1 && cy <= y2) {
                cout << cur << "\n";
                break;
            }
            ++cur;
        }
    }

    
    

}