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




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    int opt[100];
    bool states[100001];
    for (int i = 0; i < N; i++) {
        cin >> opt[i];
    }
    bool flag;
    for (int i = 0; i <= K; i++) {
        flag = false;
        for (int j = 0; j < N; j++) {
            if (opt[j] > i) {
                break;
            }
            flag = (!states[i-opt[j]] || flag);
        }
        states[i] = flag;
    }
    if (states[K]) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }

    return 0;
}