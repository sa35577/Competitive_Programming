#include <stdio.h>

int main() {
    int N,x;
    scanf("%d",&N);
    int vis[51];
    for (int i = 0; i < 51; i++) vis[i] = 0;
    while (N--) {
        scanf("%d",&x);
        vis[x]++;
    }
    x = -1;
    for (int i = 0; i < 51; i++) if (x < vis[i]*i) x = vis[i]*i;
    for (int i = 0; i < 51; i++) if (x == vis[i]*i) printf("%d\n",i);
}