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
const ll MOD = 44654641650887;
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

bool arrayEqual(int *arr1, int *arr2) {
    rep(i,0,26,1) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    initHash();
    string n,s;
    cin >> n >> s;
    int nSize = n.size(),sSize = s.size();
    int nfreq[26];
    memset(nfreq,0,sizeof(nfreq));
    rep(i,0,n.size(),1) {
        nfreq[charToInt(n[i])]++;
    }
    ll nValue = hasher(n) % MOD;
    int sfreq[26];
    memset(sfreq,0,sizeof(sfreq));
    rep(i,0,nSize,1) {
        sfreq[charToInt(s[i])]++;
    }
    if (nSize > sSize) {
        cout << 0 << endl;
        return 0;
    }
    if (nSize == sSize) {
        //cout << "lol";
        if (arrayEqual(nfreq,sfreq)) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
        //cout << (n == s ? 1 : 0) << endl;
        return 0;
    }
    if (nSize == 1) {
        int cnt = 0;
        rep(i,0,sSize,1) {
            if (s[i] == n[0]) cnt++;
        }
        cout << cnt << endl;
        return 0;
    }
    
    ll curValue = hasher(s.substr(0,nSize));
    unordered_set<ll> st;
    
    
   if (arrayEqual(nfreq,sfreq))  {
       st.insert(curValue);
       
   }
    rep(j,nSize,sSize,1) {
        ll sub = (pows[nSize]*(s[j]-'a'+1) % MOD  -  pows[0]*(s[j-nSize]-'a'+1) % MOD) % MOD;
        
        sfreq[s[j]-'a']++;
        sfreq[s[j-nSize]-'a']--;
        curValue = ((curValue + sub) % MOD + MOD) % MOD;
        curValue = (curValue * 37) % MOD;
        if (arrayEqual(nfreq,sfreq)) {
            //st.insert(hasher(s.substr(j-nSize+1,nSize)));
            st.insert(curValue);
            
        }
        
    }
    
    cout << st.size();



}