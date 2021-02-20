#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,N;
    scanf("%d%d",&t,&N);
    vector<int> v1(N),v2(N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&v1[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d",&v2[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if (t == 2) reverse(v2.begin(),v2.end());
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += max(v1[i],v2[i]);
    }
    printf("%lld\n",sum);
}