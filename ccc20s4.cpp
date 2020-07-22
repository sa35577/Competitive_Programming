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
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/


int N;
int sIndex(int idx) {
    return (idx + 2*N) % N;
}


int a = 0, b = 1, c = 2;
vector<int> aVal[3], bVal[3], cVal[3];
string s;
int aCount = 0,bCount = 0,cCount = 0;




int main() {
    string s;
    //cin >> s;
    //ifstream fin("data.in");
    cin >> s;
    
    N = s.size();
    
    rep(i,0,s.size(),1) {
        if (s[i] == 'A') ++aCount;
        else if (s[i] == 'B') ++bCount;
        else if (s[i] == 'C') ++cCount;
    }
    if (cCount == 0) {
        vector<int> aValues(s.size());
        aValues[0] = 0;
        rep(i,0,aCount,1) {
            if (s[i] != 'A') aValues[0]++;
        }

        int mnA = aValues[0];
        
        rep(i,1,s.size(),1) {
            aValues[i] = aValues[i-1];
            if (s[i-1] != 'A') aValues[i]--;
            if (s[sIndex(i+aCount-1)] != 'A') aValues[i]++;
            mnA = min(aValues[i],mnA);
            
        
        }
        cout << mnA;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        vector<int> nxt(s.size()),nxt2(s.size()),nxt3(s.size());
        aVal[i] = nxt;
        bVal[i] = nxt2;
        cVal[i] = nxt3;
    }

    rep(i,0,aCount,1) {
        if (s[i] == 'A') {
            aVal[b][0]++;
            aVal[c][0]++;
        }
        else if (s[i] == 'B') {
            aVal[a][0]++;
            aVal[c][0]++;
        }
        else {
            aVal[a][0]++;
            aVal[b][0]++;
        }
    }
    rep(i,0,bCount,1) {
        if (s[i] == 'A') {
            bVal[b][0]++;
            bVal[c][0]++;
        }
        else if (s[i] == 'B') {
            bVal[a][0]++;
            bVal[c][0]++;
        }
        else {
            bVal[a][0]++;
            bVal[b][0]++;
        }
    }
    rep(i,0,cCount,1) {
        if (s[i] == 'A') {
            cVal[b][0]++;
            cVal[c][0]++;
        }
        else if (s[i] == 'B') {
            cVal[a][0]++;
            cVal[c][0]++;
        }
        else {
            cVal[a][0]++;
            cVal[b][0]++;
        }
    }
    
    rep(i,1,s.size(),1) {
        aVal[a][i] = aVal[a][i-1]; aVal[b][i] = aVal[b][i-1]; aVal[c][i] = aVal[c][i-1];
        bVal[a][i] = bVal[a][i-1]; bVal[b][i] = bVal[b][i-1]; bVal[c][i] = bVal[c][i-1];
        cVal[a][i] = cVal[a][i-1]; cVal[b][i] = cVal[b][i-1]; cVal[c][i] = cVal[c][i-1];
        if (s[i-1] == 'A') {
            aVal[b][i]--; aVal[c][i]--;
            bVal[b][i]--; bVal[c][i]--;
            cVal[b][i]--; cVal[c][i]--;
        }
        else if (s[i-1] == 'B') {
            aVal[a][i]--; aVal[c][i]--;
            bVal[a][i]--; bVal[c][i]--;
            cVal[a][i]--; cVal[c][i]--;
        }
        else if (s[i-1] == 'C') {
            aVal[b][i]--; aVal[a][i]--;
            bVal[b][i]--; bVal[a][i]--;
            cVal[b][i]--; cVal[a][i]--;
        }
        char c1 = s[sIndex(i+aCount-1)], c2 = s[sIndex(i+bCount-1)], c3 = s[sIndex(i+cCount-1)];
        if (c1 == 'A') {
            aVal[b][i]++; aVal[c][i]++;
        }
        else if (c1 == 'B') {
            aVal[a][i]++; aVal[c][i]++;
        }
        else if (c1 == 'C') {
            aVal[b][i]++; aVal[a][i]++;
        }
        if (c2 == 'A') {
            bVal[b][i]++; bVal[c][i]++;
        }
        else if (c2 == 'B') {
            bVal[a][i]++; bVal[c][i]++;
        }
        else if (c2 == 'C') {
            bVal[b][i]++; bVal[a][i]++;
        }
        if (c3 == 'A') {
            cVal[b][i]++; cVal[c][i]++;
        }
        else if (c3 == 'B') {
            cVal[a][i]++; cVal[c][i]++;
        }
        else if (c3 == 'C') {
            cVal[b][i]++; cVal[a][i]++;
        }
    }

    int ans = 100000000;
    int ans2 = 10000000;
    rep(i,0,s.size(),1) {
        int mn = aVal[a][i] + bVal[b][sIndex(i+aCount)] - min(aCount - aVal[b][i], bCount - bVal[a][sIndex(i+aCount)]);
        int mn2 = aVal[a][i] + bVal[b][sIndex(i-bCount)] - min(aCount -aVal[b][i], bCount - bVal[a][sIndex(i-bCount)]);
        ans = min(ans,mn);
        ans2 = min(ans2,mn2);
    }
    cout << min(ans,ans2) << endl;
    


}