#include <bits/stdc++.h>
using namespace std;

int maxi(int arr[], int x, int y) {
    int w = -1;
    for (int i = x; i < y; i++) {
        w = max(w,arr[i]);
    }
    return w;
}

int main() {
    int M,Q,weight,x;
    cin >> M >> Q;
    int times[Q],names[Q];
    for (int i = 0; i < Q; i++) {
        cin >> weight >> names[i];
        if (i == 0) {
            times[i] = weight;
        }
        else if (i < M) {
            x = times[i-1] + weight;
            for (int j = 0; j < i - 1; j++) {
                x = min(x,maxi())
            }
        }
    }
    
}
