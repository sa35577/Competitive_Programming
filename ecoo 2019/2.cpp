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

unordered_map<char,string>mp;
unordered_map<int,int*>frequencies;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    rep(bob,0,10,1) {
        //ifstream fin("data.in");
        //ofstream fout("data.out");
        int r,t;
        string a;
        cin >> r >> t >> a;
        char c;
        int freq[26],nfreq[26];
        memset(freq,0,sizeof(freq));
        rep(i,0,r,1) {
            int dummy[26];
            memset(dummy,0,sizeof(dummy));
            cin >> c;
            cin >> mp[c];
            frequencies[(int)c-65] = dummy;
            for (char d : mp[c]) {
                frequencies[(int)c-65][(int)d-65]++;
            }
            
        }
        char first=a[0],last=a[a.size()-1];
        for (char c : freq) {
            freq[(int)c-65]++;
        }
        rep(i,0,t,1) {
            first = mp[first][0];
            last = mp[last][mp[first].size()-1];
            memset(nfreq,0,sizeof(nfreq));
            rep(j,0,26,1) {
                int x = freq[j];
                rep(k,0,26,1) {
                    
                }
            }


        }



    }


}