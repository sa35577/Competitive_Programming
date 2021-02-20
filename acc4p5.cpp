#include <bits/stdc++.h>

using namespace std;

bool f(int N) {
    if (N == 1) return false;
    if (N < 4) return true;
    for (int i = 2; i*i <= N; i++) if (N%i == 0) return false;
    return true;
}