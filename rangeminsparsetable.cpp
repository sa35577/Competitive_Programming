#include <bits/stdc++.h>
using namespace std;

//cols --> logn + 1 = 2+1 = 3
int main() {
    const int n = 6;
    int a = (int)log2(n) + 1;
    int arr[] = {4,6,1,5,7,3};
    int st[n][a];
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    for (int j = 1; j <= a; j++) {
        for (int i = 0; i + (1 << j) <= n; i++){
            if (st[i][j-1] > st[i + (1 << (j - 1))][j - 1]) {
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
            }
            else st[i][j] = st[i][j-1];
            
        }
    }   
    /*
    And the minimum of a range [L,R] can be computed with:

int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);*/

}