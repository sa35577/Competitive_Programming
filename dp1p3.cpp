#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    pair<int,int> arr[5001];
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&arr[i].first);
        arr[i].second = 1;
    }
    int mx = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].first < arr[i].first) arr[i].second = max(arr[i].second,arr[j].second+1);
        }
        mx = max(mx,arr[i].second);
    }
    printf("%d\n",mx);
    
    
    
}