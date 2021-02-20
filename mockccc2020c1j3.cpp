#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long prod = x*y, res = x*y/4;
    if (prod % 4 == 0) printf("%lld.00\n",res);
    else if (prod % 4 == 1) printf("%lld.25\n",res);
    else if (prod % 4 == 2) printf("%lld.50\n",res);
    else printf("%lld.75\n",res);
}