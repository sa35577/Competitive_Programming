#include <bits/stdc++.h>
using namespace std;


long long A[100005],B[100005];

int main() {
    int N;
    cin >> N;
    long long tot = 0;
    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        tot += (A[i]+A[i+1])*B[i];
    }
    if (tot % 2 == 0) {
        cout << tot/2 << "\n";
    }
    else {
        cout << tot/2 << ".5\n";
    }

}