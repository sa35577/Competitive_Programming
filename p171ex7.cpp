#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,a=0,b=0,c=0,d=0,e=0,f=0;
    while (1) {
        scanf("%d",&n);
        if (n == -1) break;
        else if (n < 10000) ++a;
        else if (n < 20000) ++b;
        else if (n < 30000) ++c;
        else if (n < 40000) ++d;
        else if (n < 50000) ++e;
        else ++f;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d",a,b,c,d,e,f);
    
}