#include <bits/stdc++.h>
using namespace std;

int N,M;
const int MX = 200005;
bitset<MX> cur;
int lightsOn = 0;

int main() {
	scanf("%d%d",&N,&M);
	for (int i = 1,x; i <= N; i++) {
		scanf("%d",&x);
		lightsOn += x;
		cur[i] = (x==1);
	}
	if (lightsOn == 0) {
		printf("0\n"); return 0;
	}
	for (int i = 1,x; i <= M; i++) {
		scanf("%d",&x);
		cur[x] = !cur[x];
		if (cur[x]) lightsOn++;
		else lightsOn--;
		if (lightsOn <= i) {
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",lightsOn);
	return 0;


}