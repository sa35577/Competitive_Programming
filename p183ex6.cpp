#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[21][21];
    memset(arr,0,sizeof(arr));
    arr[0][0] = 1;
    printf("1\n");
    for (int i = 1; i < n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        printf("1 ");
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            printf("%d ",arr[i][j]);
        }
        printf("1\n");
    }
    
}