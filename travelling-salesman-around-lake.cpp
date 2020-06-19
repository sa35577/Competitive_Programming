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


int arr[200005];
int pre[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int k,n;
    cin >> k >> n;
    memset(arr,0,sizeof(arr));
    memset(pre,0,sizeof(pre));
    for(i,0,n,1) cin >> arr[i];
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int sum = 0;
    for(i,0,n,1) {
        if (i == 0) {
            pre[i] = arr[i]-arr[n-1]+k;
        }
        else {
            pre[i] = arr[i]-arr[i-1];
        }
        sum += pre[i];
    }
    cout << sum - *max_element(pre,pre+n);



}