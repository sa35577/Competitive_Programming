//
// Created by satcl on 2020-05-04.
//

//
// Created by satcl on 2020-05-04.
//
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
#define PI 3.141592653589793
#define vi vector<int>
#define vll vector<long long>
#define p pair<int,int>
const int MOD = 1000000007;
inline double degcos(double ang) {return cos(ang*PI/180);}
inline double degsin(double ang) {return sin(ang*PI/180);}
#define rep(i,j,k,in) for (int i = j; i < k; i += in)


/*---END OF TEMPLATE---*/




int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    printf("%.10f\n",(a+b)/2);
    printf("%.10f\n",(a+c)/2);
    printf("%.10f\n",(a+d)/2);
    printf("%.10f\n",(c+b)/2);
    printf("%.10f\n",(d+b)/2);
    printf("%.10f\n",(c+d)/2);
    printf("%.10f\n",(a+b+c)/3);
    printf("%.10f\n",(a+b+d)/3);
    printf("%.10f\n",(a+c+d)/3);
    printf("%.10f\n",(b+c+d)/3);
    printf("%.10f\n",(a+b+c+d)/4);


}