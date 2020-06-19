#include <bits/stdc++.h>
using namespace std;

//pq for dist, xn + y


struct spots {
    unsigned long long DIST,L,R;
    char C;
}arr[1005][1005];


int main () {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j].C = s[j];
            arr[i][j].DIST = 1e15;
            arr[i][j].L = 0;
            arr[i][j].R = 0;
        }
    }
    priority_queue<pair<unsigned long long,int>,
    vector<pair<unsigned long long,int>>,
    greater<pair<unsigned long long,int>>> q;
    arr[0][0].DIST = 0;
    q.push({0,0});
    while (!q.empty()) {
        auto x = q.top();
        
        //y is the distance in pq
        int z = x.second;
        int a = z / n;
        int b = z % n;
        
        int l = arr[a][b].L,r = arr[a][b].R;
        if (b != 0) {
            if (arr[a][b-1].C == '.') {
                //dist = arr[a][b-1].DIST;
                if (arr[a][b-1].DIST > a*a + (l+1)*(l+1) + r*r) {
                    arr[a][b-1].DIST = a*a + (l+1)*(l+1) + r*r;
                    arr[a][b-1].L = l+1;
                    arr[a][b-1].R = r;
                    q.push({arr[a][b-1].DIST,a*n + (b-1)});
                }
            }  
        }
        if (b != n-1) {
            if (arr[a][b+1].C == '.') {
                if (arr[a][b+1].DIST > a*a + l*l + (r+1)*(r+1)) {
                    arr[a][b+1].DIST = a*a + l*l + (r+1)*(r+1);
                    arr[a][b+1].L = l;
                    arr[a][b+1].R = r+1;
                    q.push({arr[a][b+1].DIST,a*n + (b+1)});
                }
            }
        }
        if (a != n-1) {
            if (arr[a+1][b].C == '.') {
                if (arr[a+1][b].DIST > (a+1)*(a+1)+l*l+r*r) {
                    arr[a+1][b].DIST = (a+1)*(a+1)+l*l+r*r;
                    arr[a+1][b].L = l;
                    arr[a+1][b].R = r;
                    q.push({arr[a+1][b].DIST,(a+1)*n + b});
                }
            }
        }
        q.pop();
    }
    cout << arr[n-1][n-1].DIST;

}