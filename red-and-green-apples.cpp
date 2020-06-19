#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
//#define p pair<int,int>
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define for(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/
        


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int x,y,a,b,c;
    
    cin >> x >> y >> a >> b >> c;
    ll p[a];
    ll q[b];
    ll r[c];
    for (i,0,a,1) cin >> p[i];
    for (i,0,b,1) cin >> q[i];
    for (i,0,c,1) cin >> r[i];
    sort(p,p+a);
    sort(q,q+b);
    sort(r,r+c);
    int ca = a-x, cb = b-y, cc = c-1;
    while (true) {
        if (ca == a && cb == b) break;
        else if (cc == -1) break;
        else if (r[cc] <= p[ca] && r[cc] <= q[cb]) break;

        if (ca != a && cb != b) {
            if (p[ca] <= q[cb]) {
                p[ca] = r[cc];
                ca++;
                cc--;
            }
            else {
                q[cb] = r[cc];
                cb++;
                cc--;
            }
        }
        else if (ca == a){
            if (r[cc] > q[cb]) {
                q[cb] = r[cc];
                cb++;
                cc--;
            }
            else break;
        }
        else if (cb == b){
            if (r[cc] > p[ca]) {
                p[ca] = r[cc];
                ca++;
                cc--;
            }
            else break;
        }
    }
    ll tot = 0;
    for(i,a-x,a,1) {
        tot += p[i];
    }
    for (i,b-y,b,1) {
        tot += q[i];
    }
    cout << tot;




}