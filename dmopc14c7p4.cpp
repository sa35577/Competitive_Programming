#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    scanf("%lld",&N);
    if (N == 0) return 0*printf("0\n");
    if (N == 1) return 0*printf("1\n");
    long long prev = 1, cur = 1, inc = 2;
    while (cur < N) {
        prev = cur;
        cur += inc;
        inc++;
    }
    long long ans = (prev+1+cur)*(cur-(prev+1)+1);
    printf("%lld\n",ans>>1);


}