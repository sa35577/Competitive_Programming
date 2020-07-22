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
const ll MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/



ll pows[5001];
void initHash() {
    ll cur = 1;
    for (int i = 5000; i >= 0; i--) {
        cur = (cur * 37) % MOD;
        cur = (cur + MOD) % MOD;
        pows[i] = cur;
    }
}

ll hasher(const string &s) {
    ll val = 0;
    rep(i,0,s.size(),1) {
        char curChar = s[i];
        val += pows[i] * (curChar-'a');
        val = val % MOD;
    }
    if (val < 0) {
        val = (val + MOD) % MOD;
    }
    return val % MOD;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    initHash();
   
    int tc;
    cin >> tc;
    rep(i,0,tc,1) {
        string s;
        cin >> s;
        unordered_set<ll> st;
        ll tot = 0, curValue = 0;
        rep(j,0,s.size()+1,1) {
            if (j == 0) {
                st.insert(hasher(""));
            }
            else {
                curValue = hasher(s.substr(0,j));
                st.insert(curValue);
               
                rep(k,j,s.size(),1) {
                    //curValue += (pows[j]*(s[k]-'a')) % MOD;
                    ll sub = (pows[j]*(s[k]-'a') % MOD  -  pows[0]*(s[k-j]-'a') % MOD) % MOD;
                    
                    curValue = ((curValue + sub) % MOD + MOD) % MOD;
                    curValue = (curValue * 37) % MOD;
                    int sz = st.size();
                    st.insert(curValue);
                }
    
            }
            tot += st.size();
            
            st.clear();
        }
        cout << tot << endl;
    }
    
    

}
