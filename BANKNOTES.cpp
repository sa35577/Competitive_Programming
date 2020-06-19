#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long b[n],c[n];
    long long k,tot = 0;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        tot += c[i];
    }
    cin >> k;
    long long val[tot+1];
    val[0] = 0;
    long long inc = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c[i]; j++) {
            val[inc] = b[i];
            inc++;
        }
    }


    long long V[tot+2][k+1];
    for (int i = 0; i < k+1; i++)
        V[0][i] = 10000;
    for (int j = 0; j < tot+2; j++)
        V[j][0] = 0;
    for (int i = 1; i < tot+2; i++)
    for (int j = 1; j < k+1; j++)
        V[i][j] = 10000;

    for (int i = 1; i <= tot+2; i++)
    for (int j = 1; j <= k+1; j++){
        if (val[i-1] > j)
            V[i][j] = V[i-1][j];
        else
            V[i][j] = min(V[i-1][j],1+V[i-1][j-val[i-1]]);
    }


    /*
    for (int i = 0; i < tot+2; i++) {
        for (int j = 0; j < k+1; j++) {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << V[tot+1][k];
    return 0;

}
