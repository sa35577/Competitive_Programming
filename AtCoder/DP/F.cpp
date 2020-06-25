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
int L[3005][3005];
string a,b;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    
    cin >> a >> b;
    memset(L,0,sizeof(L));
    int x = a.size(), y = b.size();
    rep(i,0,x+1,1) {
        rep(j,0,y+1,1) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (a[i-1] ==  b[j-1]) {
                L[i][j] = L[i-1][j-1]+1;
            }
            else {
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    int idx = L[x][y];
    int i = x, j = y;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs = a[i-1] + lcs;
            --i;
            --j;
            --idx;
        }
        else if (L[i-1][j] > L[i][j-1]) --i;
        else j--;
    } 
    cout << lcs;



}