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
#define ld long double
#define endl "\n"
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)
#define repr(i,j,k,in) for (int i = j; i > k; i -= in)
#define repll(i,j,k,in) for (ll i = j; i < k; i += in)
#define repllr(i,j,k,in) for (ll i = j; i > k; i -= in)

/*---END OF TEMPLATE---*/
const int MAXN = 2005;
int LOG[MAXN];
vector<vector<vector<vi>>> v;
bool inBuild;

int getMin(int x1, int y1, int x2, int y2) {
    int dx = x2-x1+1, dy = y2-y1+1;

    int l1,l2;
    l1 = LOG[dx-1];
    l2 = LOG[dy-1];
    
    printf("%d %d\n",l1,l2);
    cout << v[l1][l2][x1][y1] << endl;
    cout << v[l1][l2][x1][dy-(1<<l2)+y1] << endl;
    cout << v[l1][l2][dx-(1<<l1)+x1][y1] << endl;
    cout << v[l1][l2][dx-(1<<l1)+x1][dy-(1<<l2)+y1] << endl;
    return min(min(v[l1][l2][x1][y1],
                   v[l1][l2][x1][dy-(1<<l2)+y1]),
               min(v[l1][l2][dx-(1<<l1)+x1][y1],
                   v[l1][l2][dx-(1<<l1)+x1][dy-(1<<l2)+y1]));

}

void build(vector<vi> arr) {
    LOG[0] = LOG[1] = 0;
    rep(i,2,MAXN,1) {
        LOG[i] = LOG[i>>1] + 1;
    }
    v.resize(LOG[arr.size()]+1);
    for (auto &b2 : v) {
        b2.resize(LOG[arr.size()]+1);
        for (auto &b3 : b2) {
            b3.resize(arr.size());
            for (auto &b4 : b3) {
                b4.resize(arr.size());
            }
        }
    }
    rep(i,0,arr.size(),1) rep(j,0,arr.size(),1) v[0][0][i][j] = arr[i][j];
    rep(hor,0,LOG[arr.size()]+1,1) {
        rep(ver,0,LOG[arr.size()]+1,1) {
            if (hor + ver > 0) {
                for (int i = 0; i + (1<<hor) < arr.size(); i++) {
                    for (int j = 0; j + (1<<ver) < arr.size(); j++) {
                        v[hor][ver][i][j] = getMin(i,j,i+(1<<hor)-1,j+(1<<ver)-1);
                    }
                }
            }
        }
    }
    rep(hor,0,v.size(),1) {
        rep(ver,0,v[0].size(),1) {
            rep(i,0,v[0][0].size(),1) {
                rep(j,0,v[0][0][0].size(),1) {
                    if (v[hor][ver][i][j] == 0) {
                        printf("%d %d %d %d\n",hor,ver,i,j);
                    }
                }
            }
        }
    }
}



void init(vector<vi> arr) {
    inBuild = true;
    build(arr);
    inBuild = false;
}
void query(int a, int b, int c, int d) {
    printf("%d\n",getMin(a,c,b,d));
}

int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    init({{1, 2}, {3, 4}});
    query(0, 1, 0, 1);
    //query(1, 1, 0, 1);
    //query(0, 0, 1, 1);




}