#include <bits/stdc++.h>
using namespace std;

int tri_num(int p) 
{ 
   return ceil( ( sqrt( 8*p + 1 ) -1 ) / 2 ) ; 
} 

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n,m;
    cin >> n >> m;
    if (m == 1) {
        n--;
        cout << tri_num(n);
    }
}