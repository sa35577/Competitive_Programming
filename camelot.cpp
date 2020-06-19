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

int val(double x) {
    if (x < 0) {
        return (int)x - 1;
    }
    return (int)x;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int n;
    cin >> n;
    int arr[n][2];
    int xs[n],ys[n];
    double totX = 0, totY = 0;
    rep(i,0,n,1) {
        cin >> arr[i][0] >> arr[i][1];
        xs[i] = arr[i][0] + arr[i][1];
        ys[i] = arr[i][0] - arr[i][1];
        cout << xs[i] << " " << ys[i] << endl;
    }
    sort(xs,xs+n);
    sort(ys,ys+n);
    if (n % 2 == 1) {
        totX = xs[n/2];
        totY = ys[n/2];
    }
    else {
        totX = (double)(xs[n/2] + xs[n/2 + 1])/2;
        totY = (double)(ys[n/2] + ys[n/2 + 1])/2;
    }
    cout << totX << " " << totY << endl;
    int mndist = INT_MAX;
    int dist = 0;
    int q,r;
    if (n % 2 == 1) {
        cout << "yay";
        rep(i,0,n,1) {
            q = abs(arr[i][0]-(int)totX);
            r = abs(arr[i][1]-(int)totY);
            dist += max(q,r);
        }
        cout << dist << endl;
        return 0;
    }
    else {
        rep(i,0,n,1) {
            q= abs(arr[i][0]-val(totX));
            r= abs(arr[i][1]-val(totY));
            dist += max(q,r);
        }
        mndist = min(mndist,dist);
        dist = 0;
        rep(i,0,n,1) {
            q= abs(arr[i][0]-val(totX)-1);
            r= abs(arr[i][1]-val(totY));
            dist += max(q,r);
        }
        dist = 0;
        rep(i,0,n,1) {
            q= abs(arr[i][0]-val(totX));
            r= abs(arr[i][1]-val(totY)-1);
            dist += max(q,r);
        }
        mndist = min(dist,mndist);
        dist = 0;
        rep(i,0,n,1) {

            q= abs(arr[i][0]-val(totX)-1);
            r= abs(arr[i][1]-val(totY)-1);
            dist += max(q,r);
        }
        mndist = min(dist,mndist);
        cout << mndist << endl;
        return 0;
    }

    


}