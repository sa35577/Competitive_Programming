/*
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
const ull MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/

/*

ull pows[5001];
void initHash() {
    ull cur = 1;
    for (int i = 5000; i >= 0; i--) {
        cur = (cur * 37) % MOD;
        pows[i] = cur;
    }
}

ull hasher(string s) {
    ull val = 0;
    rep(i,0,s.size(),1) {
        char curChar = s[i];
        val += pows[i] * (curChar-'a'+1);
        val = val % MOD;
    }

    //cout << val << endl;
    return val;
}
*/
/*
int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n;
    cin >> n;
    string s;
    initHash();
    rep(i,0,n,1) {
        cin >> s;
        rep(l,0,s.size(),1) {
            cout << pows[l] << " ";
        }
        cout << endl;
        set<ull> st;
        st.insert(hasher(""));
        cout << hasher("") << endl;
        string t = "";
        ull curVal = 0;
        ull tot = 0;
        rep(j,1,s.size()+1,1) {
            //t = s.substr(0,j);
            curVal = hasher(s.substr(0,j));
            //st.insert(hasher(t));
            cout << j << " " << s.substr(0,j) << endl;
            st.insert(curVal);
            rep(k,j,s.size(),1) {
                cout << j << " " << k << " " << s.substr(k-j,j) << endl;
                //curVal = (curVal * 43240495611) % MOD; //mmi(37,MOD) = 153846155
                curVal -= pows[k-j]*(ull)(s[k-j]-'a'+1) % MOD;
                curVal += pows[j]*(s[k]-'a'+1) % MOD;
                curVal = curVal % MOD;
                while (curVal < 0) curVal = (curVal+MOD) % MOD;
                curVal *= 37;
                curVal %= MOD;
                
                t += s[k];
                t = t.substr(1);
                st.insert(hasher(t));
                
                st.insert(curVal);
                //cout << s.substr(k-j,j) << " " << k-j << " " << j << " " << curVal << endl;
            }
            tot += st.size();
            for (set<ull>::iterator it = st.begin(); it != st.end(); it++) {
                cout << *it << " ";
            }
            st.clear();
            cout << endl << endl;
        }
        cout << tot << endl;
        for (unordered_set<ull>::iterator it = st.begin(); it != st.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        st.clear();
    }

}*/