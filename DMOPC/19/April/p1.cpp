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




int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //ifstream fin("data.in");
    //ofstream fout("data.out");
    int a,b,c,d;
    scan(a); scan(b); scan(c); scan(d);/*
    int n = a+b+c+1;
    int m = d;
    if (d == 0 || (a + b == 0 && c > 0)) {
        cout << "invalid";
        return 0;
    }
    if (4*n-a-2*b-3*c-1 == d) {
        cout << "C" << n << "H" << m << "\n";
    }
    else if (a+b+c==0 && d == 4) cout << "C" << n << "H" << m << "\n";
    else cout << "invalid\n";*/
    int n = a+b+c+1;
    int m = d;
    if (4*n - 6*c - 4*b - 2*a == m)  cout << "C" << n << "H" << m << "\n";
    else cout << "invalid\n";









}