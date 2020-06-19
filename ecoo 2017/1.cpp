#include <bits/stdc++.h>
using namespace std;

int main(){
    for (int i = 0; i < 10; i++){
        int t;
        scanf("%d", &t);
        float y1, y2, y3, y4;
        scanf("%f %f %f %f", &y1, &y2, &y3, &y4);
        int n;
        scanf("%d", &n);
        float newCost = y1 * n * 12 + y2 * n * 10 + y3 * n * 7 + y4 * n * 5;
        if (newCost / 2 > t) printf("NO\n");
        else printf("YES\n");
    }
}