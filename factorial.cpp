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

unordered_map<ll,ll> mp;
unordered_map<ll,ll>::iterator it;
ll M,K;
ll N;



void generateFactors() {
    ll rem = K;
    for (ll i = 2; i <= K; i++) {
        while (rem % i == 0) {
            if (mp.find(i) == mp.end()) mp[i] = 1;
            else mp[i]++;
            rem = rem / i;
        }
        if (rem == 1) break;
    }
}

bool check(ll key) {
    ll res = 0;
    ll rem = N;
    while (rem > 0) {
        res += rem / key;
        rem = rem / key;
    }
    return res/mp[key] >= M;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    rep(ecoo,0,10,1) {
        mp.clear();
        cin >> K >> M;
        generateFactors();
        ll low = 1, high = 10000000000000;
        while (low <= high) {
            N = (low + high)/2;
            bool flag = false;
            for (it = mp.begin(); it != mp.end(); it++) {
                ll key = it->first;
                if (!check(key)) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                low = N+1;
            }
            else high = N-1;

        }
        cout << low << endl;
        mp.clear();
    }


}