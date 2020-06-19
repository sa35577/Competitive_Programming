#include <bits/stdc++.h>
using namespace std;



int main(){
    int wt, wa, wp, wq;
    
    for(int i = 0; i < 10; i++){
        scanf("%d %d %d %d", &wt, &wa, &wp, &wq);
        float awt = wt/100.0, awa = wa/100.0, awp = wp/100.0, awq = wq/100.0;
        int something;
        scanf("%d", &something);
        int passing = 0;
        for(int j = 0; j < something; j++){
            int t, a, p, q;
            scanf("%d %d %d %d", &t, &a, &p, &q);
            float totalGrade = t * awt + a * awa + p * awp + q * awq;
            if (totalGrade >= 50){
                passing++;
            }
        }
        printf("%d\n", passing);
    }
}