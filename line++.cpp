#include <bits/stdc++.h>
#include <unordered_set>
#include <stdio.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI 3.141592653589793
#define vi vector<int>
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define for(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/




int dist[2005][2005];
int n;
int main()
{
    //Step 1: Input the graph using adjacency list.
    memset(dist,1,sizeof(dist));
    int x,y;
    cin >> n >> x >> y;
    x--;y--;
    int tot[2005];
    memset(tot,0,sizeof(tot));
    for (i,0,n,1) {
        for (j,0,n,1) {
            dist[j][i] = min(i-j,min(abs(i-x)+1+abs(y-j),abs(i-y)+1+abs(j-x)));
            tot[dist[j][i]]++;
        }
    }
    for (i,1,n,1) {
        cout << tot[i] << endl;
    }


    
}
