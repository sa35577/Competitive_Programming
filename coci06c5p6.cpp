#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
//#define s second
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const ll MOD = 44654641650887787;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/


ll pows[200005];
void initHash() {
    ll cur = 1;
    for (int i = 200004; i >= 0; i--) {
        cur = (cur * 37) % MOD;
        cur = (cur + MOD) % MOD;
        pows[i] = cur;
    }
}

ll hasher(const string &s) {
    ll val = 0;
    rep(i,0,s.size(),1) {
        char curChar = s[i];
        val += pows[i] * (curChar-'a'+1);
        val = val % MOD;
    }
    if (val < 0) {
        val = (val + MOD) % MOD;
    }
    return val % MOD;
}


int charToInt(char c) {
    return int(c - 'a');
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    initHash();
    //cout << hasher("a") << endl;
    string n,s;
    int nSize;
    cin >> nSize >> n;
    bool found = 0;
    if (nSize == 1) {
        printf("0\n");
        return 0;
    }
    else if (nSize == 2) {
        if (n[0] == n[1]) {
            printf("1\n");
        }
        else printf("0\n");
        return 0;
    }
    int L = 0, R = n.size()-1;
    int mid = (L+R)>>1;
    int prevMid = -1;
    while (prevMid != mid) {
        found = 0;
        if (mid == 0) {
            printf("0\n");
            return 0;
        }
        int sz = mid;
        s = n.substr(0,sz);
        int sSize = s.size();
        
        ll curValue = hasher(s);
        unordered_set<ll> st;
        st.insert(curValue);
        
        
        rep(j,sSize,nSize,1) {
            
            ll sub = (pows[sSize]*(n[j]-'a'+1) % MOD  -  pows[0]*(n[j-sSize]-'a'+1) % MOD) % MOD;
            curValue = ((curValue + sub) % MOD + MOD) % MOD;
            curValue = (curValue * 37) % MOD;
            st.insert(curValue);
            //if (sz == 2) printf("%lld ",curValue);
        }
        
        if (st.size() < nSize-sz+1) {
            found = 1;
            
        }
        st.clear();
        if (found) L = mid+1;
        else R = mid-1;
        prevMid = mid;
        mid = (L+R)>>1;
    }
    printf("%d\n",mid);
    return 0;


}