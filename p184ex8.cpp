#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    char c;
    int arr[7];
    memset(arr,0,sizeof(arr));
    while (n--) {
        cin >> c;
        if (c == 'A') arr[0]++;
        else if (c == 'B') arr[1]++;
        else if (c == 'C') arr[2]++;
        else if (c == 'D') arr[3]++;
        else if (c == 'E') arr[4]++;
        else if (c == 'F') arr[5]++;
        else arr[6]++;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6]);
    return 0;
}