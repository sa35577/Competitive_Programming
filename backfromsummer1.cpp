#include <bits/stdc++.h>
using namespace std;

int main () {
    
    int N,M;
    cin >> N >> M;
    int arr[N];
    int x,y = 1e9,z = -1;
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
        for (int j = 0; j < M; j++) {
            cin >> x;
            if (x % 9 == 1) arr[i]++;
        }
        if (arr[i] < y) {
            z = i + 1;
            y = arr[i];
        }

    }
    cout << z;

}