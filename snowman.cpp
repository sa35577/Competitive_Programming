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
int M,N,S;
vector<int> sizes;
string ground[11],groundVert[11];

bool check(int idx, string *g, string *gVert) {
    if (idx >= sizes.size()) return true;
    int val = sizes[idx];
    string goalStr = "",badStr = "";
    rep(i,0,val,1) {
         goalStr += "0";
         badStr += "X";
    }
    vector<pair<string,string>> nxt;
    string *t,*tVert;
    //sweep from g
    rep(i,0,M,1) {
        rep(j,0,N,1) {
            if (g[i].substr(j,val) == goalStr) {
                t = g;
                tVert = gVert;
                t[i] = g[i].substr(0,j)+badStr+g[i].substr(val+j);
                rep(k,j,j+val,1) {
                    tVert[k][i] = 'X';
                }
                if (check(idx+1,t,tVert)) return true;
            } 
        }
    }

    //sweep from gVert
    rep(i,0,N,1) {
        rep(j,0,M,1) {
            if (gVert[i].substr(j,val) == goalStr) {
                tVert = gVert;
                t = g;
                tVert[i] = gVert[i].substr(0,j)+badStr+gVert[i].substr(val+j);
                rep(k,j,j+val,1) {
                    t[k][i] = 'X';
                }
                if (check(idx+1,t,tVert)) return true;
            }
        }
    }
    
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    cin >> M >> N >> S;
    rep(i,0,S,1) {
        int val;
        cin >> val;
        sizes.push_back(val);
    }
    rep(i,0,M,1) cin >> ground[i];
    rep(i,0,N,1) {
        groundVert[i] = "";
        rep(j,0,M,1) {
            groundVert[i] += ground[j][i];
        }
    }
    sort(sizes.begin(),sizes.end(),greater<int>());
    if (sizes[0] > M && sizes[0] > N) {
        cout << "no\n";
        return 0;
    }
    cout << (check(0,ground,groundVert) ? "yes" : "no") << endl;


}