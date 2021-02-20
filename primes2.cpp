#include <bits/stdc++.h>
using namespace std;

const int SQRT = 31623;
const int SEG = 5000001;
bool primes[SQRT],out[SEG];
int N,M;

int main() {
	fill(primes,primes+SQRT,true);
	fill(out,out+SEG,true);
	scanf("%d%d",&N,&M);
	for (int i = 2; i < SQRT; i++) {
		if (primes[i]) {
			for (int j = 2; j < floor((SQRT-1)/i)+1; j++) {
				primes[i*j] = false;
			}
			for (int j = max(2,N/i); j <= M/i; j++) {
				if (i*j >= N) out[i*j-N] = false;
			}
		}
	}
	for (int i = 0; i < M-N+1; i++) {
		if (N > 1 || i > 0) {
			if (out[i]) printf("%d\n",i+N);
		}
	}
	return 0;
}