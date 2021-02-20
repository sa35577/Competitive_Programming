#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    bitset<1000005> vis;
	scanf("%d",&N);
	bool flag = false;
	for (int i = 0,x; i < N; i++) {
		scanf("%d",&x);
		if (vis[x]) flag = true;
		else vis[x] = true;
	}
    if (flag) printf("NO\n");
	else printf("YES\n");
}