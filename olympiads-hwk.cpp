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
const ull MOD = 1000000013;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

ull fastPow(ull base, ull power) {
    ull res = 1;
    while (power > 0) {
        if (power & 1) {
            res = (res * base) % MOD;
        } 
        base = (base * base) % MOD;
        power >>= 1;

    }
    return res;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    ull n;
    cin >> n;
    if (n == 1) {
        cout << 1;
         return 0;
    }
    if (n % 8 == 0) {
        cout << (fastPow(2,n-2) + fastPow(2,n/2-1)) % MOD;
    }
    else if (n % 8 == 1 || n % 8 == 7) {
        cout << (fastPow(2,n-2)+fastPow(2,(n+1)/2 - 2)) % MOD;
    }
    else if (n % 8 == 2 || n % 8 == 6) {
        cout << (fastPow(2,n-2)) % MOD;
    }
    else if (n % 8 == 3 || n % 8 == 5) {
        cout << (MOD + fastPow(2,n-2) - fastPow(2,(n+1)/2 - 2)) % MOD;
    }
    else if (n % 8 == 4) {
        cout << (MOD + fastPow(2,n-2) - fastPow(2,n/2-1)) % MOD;
    }

}