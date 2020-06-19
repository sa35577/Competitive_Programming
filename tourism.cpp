#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

struct p {
    unsigned long long i;
    ll v;
};
const unsigned long long MAX = 1000001, MLOG = 21;
unsigned long long n,k,day[MAX],sparse[MLOG][MAX];
ll arr[MAX],dp[MAX];

deque<p> withQuery;
deque<unsigned long long> noQuery;

inline void build() {
    for (unsigned long long i = 1; i < MLOG; i++) {
        unsigned long long jmp = 1 << (i-1), end = n - jmp;
        for (unsigned long long j = 1; j <= end; j++) {
            if (sparse[i-1][j] > sparse[i-1][j-jmp]) sparse[i][j] = sparse[i-1][j];
            else sparse[i][j] = sparse[i-1][j+jmp];
        }
    }
}

inline unsigned long long qmax(unsigned long long l, unsigned long long r) {
    unsigned long long delta = r-l+1, bit = 31 - __builtin_clz(delta); //number of trailing zeros (getting log)
    return max(sparse[bit][l],sparse[bit][r - (1 << bit) + 1]); //power of 2, bit number of zeros


}

int main() {
    cin >> n >> k;
    unsigned long long counter = 0, cday = 0;
    for (unsigned long long i = 1; i <= n; i++) {
        cin >> arr[i];
        sparse[0][i] = arr[i];

        if (counter == 0) ++cday;
        day[i] = cday;
        counter += 1;
        counter %= k;
    }
    build();
    cday = 0;
    unsigned long long cmax = 0;
    for (unsigned long long i = 1; i <= n; i++) {
        if (day[i] > cday) {
            for (unsigned long long j = max(0,i-k); j < i; j++) {
                ll withQueryAlt = dp[j] + qmax(j+1,i);
                while (!withQuery.empty() && withQuery.back().v < withQueryAlt) {
                    withQuery.pop_back();
                } 
                while (!noQuery.empty() && dp[noQuery.back()] < dp[j]) {
                    noQuery.pop_back();
                }
                withQuery.push_back({j,withQueryAlt});
            noQuery.push_back(j);
            }
            ++cday;
            cmax = 0;
        }
        cmax = max(cmax,(unsigned long long)arr[i]);
        while (withQuery.front().i < i - k) {
            withQuery.pop_front();
        }
        while (noQuery.front() < i - k) {
            noQuery.pop_front();
        }
        dp[i] = max(withQuery.front().v,dp[noQuery.front()]+cmax); 
    }
    cout << dp[n] << endl;
}